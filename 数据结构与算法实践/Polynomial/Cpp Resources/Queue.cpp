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
    SmallNode* new_rear = new SmallNode(item); // Ϊ��Ԫ�ط����ڴ�
    if (new_rear == 0) return overflow;
    if (rear == 0) front = new_rear; // �������Ϊ�գ���Ԫ�ؾ��Ƕ���Ԫ��
    else rear->next = new_rear; // ������в�Ϊ�գ���Ԫ�ؾ��Ƕ�βԪ��
    rear = new_rear; // ���¶�βָ��
    return success;

}

/*
* Pre : The Queue Isn't Empty.
* Post: Output The Element With Removing It From The Queue.
*/
Queue_Error_code Queue::serve() {
    if (front == 0) return underflow;
    SmallNode* old_front = front; // �������Ԫ��
    front = old_front->next; // ���¶���ָ��
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
    // ��������ʱ������ջԪ�ض��ᱻ�����.
    // ��������ڴ�й©���ڶ����������ڽ���ʱ���������ռ�õ���Դ.
    while (!empty()) {
        serve();
    }
}