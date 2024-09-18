//
// Created by Deralive (10235101526) on 2024/4/6.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include"Node.h"

using namespace std;

/*
 * Pre : None.
 * Post: When defining an object, call the constructor.
 */
template<class T>
Node<T>::Node() {
    next = NULL;
}

/*
 * Pre : None.
 * Post: When defining an object, call the constructor.
 */
template<class T>
Node<T>::Node(T item, Node *add_on) {
    data = item;
    next = add_on;
}

/*
 * Pre : None.
 * Post: Inserted node using head insertion method.
 */
template<class T>
Node<T> *Node<T>::HeadInsert(Node *head, T item) {
    Node *newNode = new Node(item);
    if (!head) {
        head = newNode;
        head->next = head; // 形成循环链表
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
    cout << "Successfully inserted node using head insertion method : " << item << endl;
    return head;
}

/*
 * Pre : None.
 * Post: Inserted node using tail insertion method.
 */
template<class T>
Node<T> *Node<T>::TailInsert(Node *head, T item) {
    Node *newNode = new Node(item);  // 新建一个指向节点
    if (!head) {
        head = newNode;
        head->next = head; // 形成循环链表的关键点，让最后一个指针指向头部
    } else {
        newNode->next = head->next;
        head->next = newNode;
        head = newNode; // 更新头节点为新插入的节点
    }
    cout << "Successfully inserted node using tail insertion method : " << item << endl;
    return head;
}

/*
 * Pre : When an element already exists in an existing linked list.
 * Post: Delete this node.
 */
template<class T>
void Node<T>::deleteNode(Node *head, int key) {
    if (!head) return; // 防御性做法，当头指针为空时，马上结束程序，不会导致后面的程序崩溃

    Node *temp = head;
    Node *prev = nullptr;

    // 查找要删除的节点
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 如果找到了要删除的节点
    if (temp && temp->data == key) {
        // 如果要删除的节点是头节点
        if (temp == head) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
}

/*
 * Pre : The program is over.
 * Post: Release resources and clear status.
 */
template<class T>
Node<T>::~Node() {
    // Todo
}