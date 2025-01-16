#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>
#include <netdb.h> // for getaddrinfo

#define DEFAULT_SERVER_PORT 12345
#define MAX_LINE 20480

typedef struct {
    int sockfd;
} thread_args_t;

volatile sig_atomic_t running = 1; // 全局标志变量，用于控制主线程的退出

// 接收线程函数：持续从服务器接收消息并打印
void *recv_thread_func(void *arg) {
    thread_args_t *targs = (thread_args_t *)arg;
    int sockfd = targs->sockfd; // 获取套接字描述符
    char recv_buffer[1024];
    ssize_t n;

    while (running) {
        memset(recv_buffer, 0, sizeof(recv_buffer));
        n = recv(sockfd, recv_buffer, sizeof(recv_buffer) - 1, 0); // 0 表示阻塞接收模式
        // 返回值为 0，表示服务器关闭了连接
        if (n <= 0) {
            if (n < 0) {
                fprintf(stderr, "Error receiving message: %s\n", strerror(errno));
            } else {
                fprintf(stderr, "Server closed connection.\n Input anything and <Enter> to exit.");
            }
            running = 0;
            close(sockfd);
            exit(EXIT_SUCCESS);
        }
        printf("\n[Message from server]: %s\n> ", recv_buffer);
        fflush(stdout);
    }
    return NULL;
}

// 从标准输入读取消息，直到两个回车为结束标志
void read_input(char *buffer) {
    char temp[MAX_LINE];
    int idx = 0;
    while (fgets(temp, sizeof(temp), stdin) && (running)) { // 从标准输入流中读取
        // 如果是连续两个回车，移除最后一个回车，保证字符串正确
        if (strcmp(temp, "\n") == 0 && idx > 0 && buffer[idx - 1] == '\n') {
            buffer[idx - 1] = '\0'; // 移除最后一个回车
            return;                 // 此时可以 return，代表结束标志
        }

        // 如果一行里输入得太长了，报错并退出
        if (idx + strlen(temp) >= MAX_LINE) {
            fprintf(stderr, "Input too large.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(buffer + idx, temp); // 追加本行内容到 buffer 数组中
        idx += strlen(temp);
    }
}

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE];
    int server_port = DEFAULT_SERVER_PORT;
    char *server_ip;

    if (argc == 3) {
        server_ip = argv[1];
        server_port = atoi(argv[2]);
        if (server_port <= 0 || server_port > 65535) {
            fprintf(stderr, "Invalid server port: %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }
    else {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 创建Socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 使用 getaddrinfo 解析域名或 IP 地址
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;       // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    int ret = getaddrinfo(server_ip, NULL, &hints, &res);
    if (ret != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(ret));
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in *addr_in = (struct sockaddr_in *)res->ai_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = addr_in->sin_addr;
    server_addr.sin_port = htons(server_port);

    freeaddrinfo(res);

    // 设置连接超时
    struct timeval timeout;
    timeout.tv_sec = 3; // 超时时间为 5 秒
    timeout.tv_usec = 0;
    setsockopt(client_socket, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
    // 这里只设置发送的超时时间，不要设置接收的 SO_REVTIMEO 超时，否则连接上了也会断开

    // 尝试连接
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server %s:%d.\n. Enter your message (end with double ENTER):\n", server_ip, server_port);

    // 创建接收线程
    pthread_t recv_tid;
    thread_args_t targs;
    targs.sockfd = client_socket;
    if (pthread_create(&recv_tid, NULL, recv_thread_func, &targs) != 0)
    {
        fprintf(stderr, "Creating receive thread failed: %s\n", strerror(errno));
        close(client_socket);
        exit(EXIT_FAILURE);
    }
    pthread_detach(recv_tid);

    // 主循环：读取输入并发送消息
    while (running) {
        memset(buffer, 0, sizeof(buffer));
        printf("> ");
        fflush(stdout); // 刷新缓冲区，确保提示符显示
        read_input(buffer); // 读取输入

        // 如果是从文件中读取文本发送
        if (strncmp(buffer, "FILE:", 5) == 0) {
            char filename[MAX_LINE];
            sscanf(buffer + 5, "%s", filename); // 提取文件名

            FILE *file = fopen(filename, "r");
            if (!file) {
                perror("Failed to open file");
                continue;
            }

            // 从文件中读取文本并发送
            char file_buffer[1024];
            size_t bytes_read;
            while (((bytes_read = fread(file_buffer, 1, sizeof(file_buffer), file)) > 0) && (running)) {
                ssize_t bytes_sent = send(client_socket, file_buffer, bytes_read, 0); // 逐块发送文件内容
                if (bytes_sent < 0) {
                    perror("Failed to send file");
                    break;
                }
            }
            fclose(file);
            printf("Text from file %s sent successfully.\n", filename);
        } else {
            // 否则，发送普通消息
            size_t total_sent = 0;
            size_t message_length = strlen(buffer);
            while ((total_sent < message_length) && (running)) {
                ssize_t bytes_sent = send(client_socket, buffer + total_sent, message_length - total_sent, 0);
                if (bytes_sent < 0) {
                    perror("Failed to send message");
                    break;
                }
                total_sent += bytes_sent;
            }
        }
    }

    close(client_socket);
    return 0;
}
