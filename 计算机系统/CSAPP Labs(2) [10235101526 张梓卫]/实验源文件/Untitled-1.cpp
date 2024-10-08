
#include <bits/stdc++.h>
using namespace std;


void phase_2(char* get) {

    int arr[10];
    read_six_numbers(get, arr[]);

    if (arr[1] != 1) {
        explode_bomb();
    }

    for (int i = 2; i < 6; i++) {
        if (arr[i] != 2 * arr[i - 1]) {
            explode_bomb();
        }
    }
}

void phase_3(char* input) {
    int arr[6];
    int result = sscanf(input, "%d %d", arr + 2, arr + 3);
    if (result <= 1) {
        explode_bomb();
    }
    int eax = arr[2];
    switch (eax) {
    case 0:
        eax = 207;
        break;
    case 1:
        eax = 311;
        break;
    case 2:
        eax = 707;
        break;
    case 3:
        eax = 256;
        break;
    case 4:
        eax = 389;
        break;
    case 5:
        eax = 206;
        break;
    case 6:
        eax = 682;
        break;
    case 7:
        eax = 327;
        break;
    default:
        explode_bomb();
    }
    if (eax != arr[3]) {
        explode_bomb();
    }
}

void phase_1(char* rdi) {
    char* esi = (char*)0x402400;
    int eax = string_no_equal(rdi, esi);
    if (eax == 0) {
        explode_bomb();
    }
    return;
}

int func4(int First, int Second, int Third) {

    // First in %edi, Second in %esi, Third in %rdx
    int result = Third;
    result = result - Second;
    int temp = result;
    temp = temp >> 31;
    result = result + temp;
    result = result >> 1;
    temp = result + Second;

    if (First - temp < 0) {
        Third = temp - 1;
        func4(First, Second, Third);
        result = result + result;
        return result;
    }
    else {
        result = 0;
        if (First - temp > 0) {
            return result;
        }
        else {
            Second = temp + 1;
            func4(First, Second, Third);
            result = result + result + 1;
            return result;
        }
        return result;
    }
}

void phase_4(int rdx, int rcx, char* input) {
    int ret = 0;
    ret = sscanf(input, (char*)0x4025cf, &rcx, &rdx);
    if (ret != 2 || rcx > 14) {
        explode_bomb();
    }
    else {
        int ret = func4(rdx, 0, 14);
        if (ret != 0 || rcx != 0) {
            explode_bomb();
        }
    }
}

int func5(int rdi) {
    int rax = 0;
    if (rdi <= 1) {
        rax = 1;
    }
    else {
        rax = func5(rdi - 1) + func5(rdi - 2);
    }
    return rax;
}

int string_length();

void phase_5(char* s) {
    const char con[16] = "maduiersnfotvbyl";
    char str[6];
    if (string_length(s) != 6) {
        explode_bomb();
    }

    for (int i = 0; i < 6; i++) {
        char temp = s[i] & 0xf;
        str[i] = con[temp];
    }

    if (string_no_equal(str, "flyers") != 0) {
        explode_bomb();
    }
}

typedef struct {
    int val;
    ListNode* next;
} ListNode;

void phase_6(char* output) {
    int array[6];
    ListNode* node_array[6];
    read_six_numbers(output, array);
    // 数字范围必须为1-6且互不重复
    for (int i = 0; i != 6; i++) {
        int num = array[i];
        num--;
        if ((unsigned int)num > 5)		// 最大为6
            explode_bomb();
        for (int j = i + 1; j <= 5; j++) {
            if (array[i] == array[j])	// 每个元素都不重复
                explode_bomb();
        }
    }
    // 修改 array
    for (int i = 0; i < 6; i++) {
        array[i] = (7 - array[i]);
    }
    // 生成 node_array
    for (int i = 0; i < 6; i++) {
        int cur = array[i];
        ListNode* node = 0x6032d0;		// 链表head
        if (cur > 1) {
            for (int j = 1; j < cur; j++) {
                node = node->next;
            }
        }
        node_array[i] = node;
    }
    for (int i = 0; i < 5; i++) {
        node_array[i]->next = node_array[i + 1];
    }
    //0x6032d0 0x6032e0 0x6032f0 0x603300 0x603310 0x603320
    //332 168 924 691 477 443
    // 6 5 4 3 2 1
    ListNode* ptr = node_array[0];
    for (int i = 5; i > 0; i--) {
        if (ptr->val < ptr->next->val)
            explode_bomb();
        ptr = ptr->next;
    }
}

// 生成 node_array
for (int i = 0; i < 6; i++) {
    int cur = array[i];
    ListNode* node = 0x6032d0;		// 链表头指针的地址
    if (cur > 1) {
        for (int j = 1; j < cur; j++) {
            node = node->next;
        }
    }
    node_array[i] = node;
}

for (int i = 0; i < 5; i++) {
    node_array[i]->next = node_array[i + 1];
}

ListNode* ptr = node_array[0];
for (int i = 5; i > 0; i--) {
    if (ptr->val < ptr->next->val)
        explode_bomb();
    ptr = ptr->next;
}