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
        head->next = head; // �γ�ѭ������
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
    Node *newNode = new Node(item);  // �½�һ��ָ��ڵ�
    if (!head) {
        head = newNode;
        head->next = head; // �γ�ѭ������Ĺؼ��㣬�����һ��ָ��ָ��ͷ��
    } else {
        newNode->next = head->next;
        head->next = newNode;
        head = newNode; // ����ͷ�ڵ�Ϊ�²���Ľڵ�
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
    if (!head) return; // ��������������ͷָ��Ϊ��ʱ�����Ͻ������򣬲��ᵼ�º���ĳ������

    Node *temp = head;
    Node *prev = nullptr;

    // ����Ҫɾ���Ľڵ�
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // ����ҵ���Ҫɾ���Ľڵ�
    if (temp && temp->data == key) {
        // ���Ҫɾ���Ľڵ���ͷ�ڵ�
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