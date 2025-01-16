#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define DEFAULT_SERVER_PORT 12345
#define MAX_LINE 20480 // 支持长文本消息
#define MAX_PENDING 5
#define MAX_CLIENTS 10

// 客户端套接字列表和互斥锁
int client_sockets[MAX_CLIENTS];
pthread_mutex_t client_list_mutex = PTHREAD_MUTEX_INITIALIZER;

// 处理广播消息的函数
void broadcast_message(const char *message)
{
    pthread_mutex_lock(&client_list_mutex); // 加锁，避免并发修改客户端列表

    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (client_sockets[i] != 0)
        {
            ssize_t bytes_sent = send(client_sockets[i], message, strlen(message), 0);
            if (bytes_sent < 0)
            {
                perror("Failed to send message to client");
            }
        }
    }

    pthread_mutex_unlock(&client_list_mutex); // 解锁
}

//  POSIX 线程库的线程函数必须接受 void* 类型参数，因此需要强制转换。
void *client_handler(void *client_socket_ptr) {
    int client_socket = *(int *)client_socket_ptr; // 动态分配内存，避免 client_socket 被覆盖
    free(client_socket_ptr);

    char buffer[MAX_LINE];
    ssize_t bytes_received;

    // 将客户端加入到客户端列表
    pthread_mutex_lock(&client_list_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == 0) {
            client_sockets[i] = client_socket;
            break;
        }
    }
    pthread_mutex_unlock(&client_list_mutex);

    while (1) {
        memset(buffer, 0, sizeof(buffer)); // 接受消息之前，将缓存区清空，防止信息混乱
        bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        // 确保保留最后一个字节给字符串的终止符 '\0'，最后的参数 0 为标志位
        if (bytes_received <= 0) {
            printf("Client disconnected.\n");

            // 客户端断开连接时，从客户端列表中移除
            pthread_mutex_lock(&client_list_mutex);
            for (int i = 0; i < MAX_CLIENTS; i++)
            {
                if (client_sockets[i] == client_socket)
                {
                    client_sockets[i] = 0;
                    break;
                }
            }
            pthread_mutex_unlock(&client_list_mutex);

            break;
        }
        printf("Received from client: %s\n", buffer);

        // 检查是否是广播命令
        if (strncmp(buffer, "BROADCAST:", 10) == 0) {
            char *message = buffer + 10; // 跳过 "broadcast:" 部分
            broadcast_message(message);  // 广播消息
        } else {
            // 获取当前时间
            time_t now = time(NULL);
            struct tm *t = localtime(&now);
            char time_str[64];
            strftime(time_str, sizeof(time_str) - 1, "%Y-%m-%d %H:%M:%S", t);

            // 构造回复消息
            char reply[MAX_LINE];
            snprintf(reply, sizeof(reply), "Server received your message at %s\n", time_str);

            // 发送回复消息给客户端
            ssize_t bytes_sent = send(client_socket, reply, strlen(reply), 0);
            if (bytes_sent < 0) {
                perror("Send response message failed");
                break;
            }
        }
    }

    close(client_socket);
    return NULL;
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int server_port = DEFAULT_SERVER_PORT;

    // 解析命令行参数
    if (argc == 2) {
        server_port = atoi(argv[1]);
        if (server_port <= 0 || server_port > 65535) {
            fprintf(stderr, "Invalid port number: %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    } else if (argc > 2) {
        fprintf(stderr, "Usage: %s [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 创建Socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 复用地址避免重启服务器时的"Address already in use"
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 配置服务器地址
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);

    // 绑定Socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // 监听连接
    if (listen(server_socket, MAX_PENDING) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", server_port);

    while (1) {
        // 接受客户端连接
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        printf("New client connected.\n");

        // 创建线程处理客户端
        pthread_t thread_id;
        int *client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = client_socket;

        if (pthread_create(&thread_id, NULL, client_handler, client_socket_ptr) != 0) {
            perror("Thread creation failed");
            free(client_socket_ptr);
            close(client_socket);
        }
        pthread_detach(thread_id);
        // 这个函数是线程分离用的。将线程标记为分离状态。
        // 线程执行结束后系统会自动回收资源，无需通过 pthread_join() 等待线程结束。
        // 分离线程适用于短期任务，主线程不关心线程的返回值或执行状态。
    }
    close(server_socket);
    return 0;
}
