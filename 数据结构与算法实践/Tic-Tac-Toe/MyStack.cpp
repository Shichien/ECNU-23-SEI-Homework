//
// Projected By Deralive (10235101526), release on 08/03/2024
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Node.cpp"
#include "MyStack.h"

#include <iostream>
using namespace std;

/*
* Pre : None.
* Post: Initialize The MyStack.
*/
template <class T>
MyStack<T>::MyStack() {
    top_node = nullptr; // ��ʼ��ջ��ͷָ��Ϊ��

    /* Node<T>* top_node �ڹ��캯���б�����Ϊ�ֲ���������������Ϊ���Ա����
    * ���캯��������top_node �ͻᱻ����
    * �����������Ա������Ȼ��ͼ���������ᵼ�� Segmentation Fault
    * �ڹ��캯���в�Ҫ����������Node<T>* top_node��ֱ�Ӷ����Ա���� top_node ����ʼֵ����
    */
}

/*
* Pre : The MyStack Is Already Initialized.
* Post: Check The MyStack Is Empty Or Not.
*/
template <class T>
bool MyStack<T>::empty() const {
    return (top_node == nullptr);
}

/*
* Pre : The MyStack Is Already Initialized, Less Than MyStack's Maxsize.
* Post: Push The Item Into The MyStack.
*/
template <class T>
State MyStack<T>::push(const T& Item) {
    Node<T>* new_top = new Node<T>(Item, top_node);
    if (new_top == nullptr) {  // ��ͷָ����Ϊ�գ�˵������ʧ��
        // cout << "The stack is overflow" << endl;
        return Overflow;
    }
    else {
        top_node = new_top; // ͷָ��ָ���¼����Ԫ��
        return Success;
    }
}

/*
* Pre : The MyStack Is Already Initialized.
* Post: Output The Top Item In The MyStack To User.
*/
template <class T>
State MyStack<T>::top(T& Item) const {
    if (top_node == nullptr) {
        // cout << "The stack is underflow!" << endl;
        return Underflow;
    }
    else {
        Item = top_node->data; // ��ȡ������Ϊ��ʱͷָ��ָ�������
        return Success;
    }
}

/*
* Pre : The MyStack Is Already Initialized, And At Lease One Item.
* Post: Pop The Top Item In The MyStack.
*/
template <class T>
State MyStack<T>::pop() {
    Node<T>* old_top = top_node;
    if (top_node == nullptr) {
        // cout << "The stack is empty!" << endl;
        return Underflow;
    }
    else {
        top_node = old_top->next; // ͷָ����ԭ��ͷָ��ָ�����һ���ڵ�
        delete old_top; // ɾ��ԭͷ����ָ�룬ģ��Ԫ�ر�ɾ��
        return Success;
    }
}

/*
* Pre : None.
* Post: Return the top_node pointer.
*/
template <class T>
Node<T>* MyStack<T>::GetTop() const {
    return top_node; // ��ջΪ�գ��򷵻� nullptr.
}

/*
* Pre : The MyStack object exists.
* Post: All elements in the stack are removed, and memory associated with each node is deallocated.
*/
template<class T>
MyStack<T>::~MyStack() {
    // ��������ʱ������ջԪ�ض��ᱻ�����.
    // ��������ڴ�й©���ڶ����������ڽ���ʱ���������ռ�õ���Դ.
    while (!empty()) {
        pop();
    }
}