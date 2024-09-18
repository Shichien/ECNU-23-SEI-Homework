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

// ���������
template<class T>
void Queue<T>::operator=(const Queue& original) {

    // �½�����ָ�뱣�� Que2 �Ŀ�ͷ�ͽ�β
    Node<T>* new_front;
    Node<T>* new_rear;

    Node<T>* new_copy; // temp 
    Node<T>* original_front = original.front;

    // ��Ȼ�����������Ϊ��ʱ���� Que2 Ҳ��Ϊ��.
    if (original_front == nullptr) {
        new_front = nullptr;
        new_rear = nullptr;
    }
    else {
        // �����������еĸ��ڵ�
        new_copy = new_front = new Node<T>(original_front->data); // �����¿ռ�
        while (original_front->next != nullptr) {  // ֱ�����һ���ڵ㣬��һ��ָ��Ϊ��ʱ�������ѵ����������
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
    // �½�һ���ڵ㣬����ڵ���ΪβԪ�أ���ָ����һ���ڵ��ָ��Ϊ��
    Node<T>* new_rear = new Node<T>(Item, nullptr);
    // �����д�ʱΪ�գ����½ڵ��ΪΨһ��Ԫ��
    if (empty()) front = rear = new_rear;
    // �����½ڵ�ʧ��ʱ���������
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

    // ע�⣺ �� Front ָ������Ӧ���� Front �� A �� B �� Rear �� Null
    else {
        Node<T>* new_front;
        if (front != nullptr) {
            new_front = front->next;
            delete front;
            front = new_front;
        }
        // ��һ���ǳ���Ҫ����Ϊempty()�����жϵ��� rear = 0 ? 1 : 0
        if (front == nullptr) rear = 0;     //  ���frontָ��Ҳ���ˣ�˵��������û��Ԫ����
        // cout << "Operation Success! Now The Queue Size Is:" << Count << endl;
        return Success;
    }

    //��һ��ʵ�ַ���

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
    // ��������ʱ������ջԪ�ض��ᱻ�����.
    // ��������ڴ�й©���ڶ����������ڽ���ʱ���������ռ�õ���Դ.
    while (!empty()) {
        serve();
    }
}

