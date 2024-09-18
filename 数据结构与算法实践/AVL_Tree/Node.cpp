//
// Created by Deralive (10235101526) on 2024/4/11.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Node.h"

/*
* Pre : When the object is created.
* Post: The initialization header pointer is grounded, indicating that there are no elements in the stack at this time.
*/
template<class T>
Node<T>::Node() {
    next = nullptr; // 初始化节点，此时指针接地
}

/*
* Pre : When the object is created.
* Post: A new node is created, passing in data and a pointer to the next node
*/
template<class T>
Node<T>::Node(T item, Node *add_on) {
    data = item;    // 传入数据
    next = add_on;  // 以及提供新的指向新节点的指针
}