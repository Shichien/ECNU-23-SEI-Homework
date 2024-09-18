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
    next = nullptr; // ��ʼ���ڵ㣬��ʱָ��ӵ�
}

/*
* Pre : When the object is created.
* Post: A new node is created, passing in data and a pointer to the next node
*/
template<class T>
Node<T>::Node(T item, Node *add_on) {
    data = item;    // ��������
    next = add_on;  // �Լ��ṩ�µ�ָ���½ڵ��ָ��
}