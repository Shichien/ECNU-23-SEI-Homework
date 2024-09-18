//
// Created by Deralive (10235101526) on 2024/03/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Queue.h"

typedef Term Queue_entry;

/*
* Pre : None.
* Post: Initialize The Stack (Constructor Function).
*/
Queue::Queue() {
    front = rear = 0;
}

/*
* Pre : None.
* Post: Check the queue is empty or not.
*/
bool Queue::empty() const {
    return front == 0;
}

/*
* Pre : The Queue Is Already Initialized.
* Post: Insert An Element Into The Queue.
*/
Queue_Error_code Queue::append(const Queue_entry& item) {
    SmallNode* new_rear = new SmallNode(item); // 为新元素分配内存
    if (new_rear == 0) return overflow;
    if (rear == 0) front = new_rear; // 如果队列为空，新元素就是队首元素
    else rear->next = new_rear; // 如果队列不为空，新元素就是队尾元素
    rear = new_rear; // 更新队尾指针
    return success;

}

/*
* Pre : The Queue Isn't Empty.
* Post: Output The Element With Removing It From The Queue.
*/
Queue_Error_code Queue::serve() {
    if (front == 0) return underflow;
    SmallNode* old_front = front; // 保存队首元素
    front = old_front->next; // 更新队首指针
    if (front == 0) rear = 0;
    delete old_front;
    return success;
}

/*
* Pre : At Least One Element In The Queue.
* Post: Output The Element Without Removing It From The Queue.
*/
Queue_Error_code Queue::retrieve(Queue_entry& item) const {
    if (front == 0) return underflow;
    item = front->entry;
    return success;
}

// safety features for linked structures
/*
* Pre : The queue object exists.
* Post: All elements in the stack are removed, and memory associated with each node is deallocated.
*/
Queue::~Queue() {
    // 对象被销毁时，所有栈元素都会被清理掉.
    // 不会造成内存泄漏，在对象生命周期结束时清理对象所占用的资源.
    while (!empty()) {
        serve();
    }
}