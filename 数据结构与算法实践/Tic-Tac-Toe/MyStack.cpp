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
    top_node = nullptr; // 初始化栈，头指针为空

    /* Node<T>* top_node 在构造函数中被声明为局部变量，而不是作为类成员变量
    * 构造函数结束后，top_node 就会被销毁
    * 若类的其他成员函数仍然试图访问它，会导致 Segmentation Fault
    * 在构造函数中不要重新声明（Node<T>* top_node，直接对类成员变量 top_node 赋初始值即可
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
    if (new_top == nullptr) {  // 新头指针若为空，说明创建失败
        // cout << "The stack is overflow" << endl;
        return Overflow;
    }
    else {
        top_node = new_top; // 头指针指向新加入的元素
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
        Item = top_node->data; // 读取的数据为此时头指针指向的数据
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
        top_node = old_top->next; // 头指针变成原来头指针指向的下一个节点
        delete old_top; // 删除原头部的指针，模拟元素被删除
        return Success;
    }
}

/*
* Pre : None.
* Post: Return the top_node pointer.
*/
template <class T>
Node<T>* MyStack<T>::GetTop() const {
    return top_node; // 若栈为空，则返回 nullptr.
}

/*
* Pre : The MyStack object exists.
* Post: All elements in the stack are removed, and memory associated with each node is deallocated.
*/
template<class T>
MyStack<T>::~MyStack() {
    // 对象被销毁时，所有栈元素都会被清理掉.
    // 不会造成内存泄漏，在对象生命周期结束时清理对象所占用的资源.
    while (!empty()) {
        pop();
    }
}