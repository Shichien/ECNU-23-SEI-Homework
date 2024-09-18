//
// Created by Deralive (10235101526) on 2024/3/19.
// Reedit on 2024/4/18
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include<iostream>
#include"Queue.h"

using namespace std;

/*
* Pre : None.
* Post: Initialize The Stack (Constructor Function).
*/
template<class T>
Queue<T>::Queue() {
    front = nullptr;
    rear = nullptr;
}

/*
* Pre : The first queue is initialized.
* Post: The second queue will be equal to the first one.
*/

// 重载运算符
template<class T>
void Queue<T>::operator=(const Queue& original) {

    // 新建两个指针保存 Que2 的开头和结尾
    Node<T>* new_front;
    Node<T>* new_rear;

    Node<T>* new_copy; // temp 
    Node<T>* original_front = original.front;

    // 显然，当最初队列为空时，将 Que2 也置为空.
    if (original_front == nullptr) {
        new_front = nullptr;
        new_rear = nullptr;
    }
    else {
        // 复制链队列中的各节点
        new_copy = new_front = new Node<T>(original_front->data); // 开辟新空间
        while (original_front->next != nullptr) {  // 直到最后一个节点，下一个指针为空时，代表已到达链表最后
            original_front = original_front->next;
            new_copy->next = new Node<T>(original_front->data);
            new_copy = new_copy->next;
        }
        new_rear = new_copy;
    }
    while (!empty()) serve(); // Clean out old Queue entries
    front = new_front;
    rear = new_rear;
}

/*
* Pre : None.
* Post: Check the queue is empty or not.
*/
template<class T>
bool Queue<T>::empty() const {
    return (rear == nullptr);
}

/*
* Pre : The Queue Is Already Initialized.
* Post: Insert An Element Into The Queue.
*/
template<class T>
State Queue<T>::append(const T& Item) {
    // 新建一个节点，这个节点作为尾元素，其指向下一个节点的指针为空
    Node<T>* new_rear = new Node<T>(Item, nullptr);
    // 若队列此时为空，则新节点成为唯一的元素
    if (empty()) front = rear = new_rear;
    // 创建新节点失败时，返回溢出
    if (new_rear == nullptr) return Overflow;
    else {
        rear->next = new_rear;
        rear = new_rear;
        return Success;
    }
}

/*
* Pre : The Queue Isn't Empty.
* Post: Output The Element With Removing It From The Queue.
*/
template<class T>
State Queue<T>::serve() {
    if (empty()) {
        // cout << "The Queue Is Empty!" << endl;
        return Underflow;
    }

    // 注意： 对 Front 指针的理解应该是 Front → A → B → Rear → Null
    else {
        Node<T>* new_front;
        if (front != nullptr) {
            new_front = front->next;
            delete front;
            front = new_front;
        }
        // 这一步非常重要，因为empty()函数判断的是 rear = 0 ? 1 : 0
        if (front == nullptr) rear = 0;     //  如果front指针也空了，说明队列中没有元素了
        // cout << "Operation Success! Now The Queue Size Is:" << Count << endl;
        return Success;
    }

    //另一种实现方法

        // {
        //     if (front == 0) {
        //         return underflow;
        //     }

        //     Node* old_front = front;
        //     front = old_front->next;
        //     if (front == 0) {
        //         rear = 0;
        //     }

        //     delete old_front;
        //     return success;
        // }
}

/*
* Pre : At Least One Element In The Queue.
* Post: Output The Element Without Removing It From The Queue.
*/
template<class T>
State Queue<T>::retrieve(T& Item) const {
    if (empty()) {
        // cout << "The Queue Is Empty!" << endl;
        return Underflow;
    }
    else {
        Item = front->data;
        return Success;
    }
}

/*
* Pre : The queue object exists.
* Post: All elements in the stack are removed, and memory associated with each node is deallocated.
*/
template<class T>
Queue<T>::~Queue() {
    // 对象被销毁时，所有栈元素都会被清理掉.
    // 不会造成内存泄漏，在对象生命周期结束时清理对象所占用的资源.
    while (!empty()) {
        serve();
    }
}

