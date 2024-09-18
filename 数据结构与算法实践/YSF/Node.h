//
// Created by Deralive (10235101526) on 2024/4/6.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>

// Define template class Node

template<class T>
class Node {
public:
    T data; //  ����ýڵ������
    Node *next; //  ������һ���ڵ�ĵ�ַ

    // ���캯������������
    Node();     //  �ڳ�ʼ��ʱ�������ô��޲ι��캯�������սڵ�
    Node(T item, Node *add_on = nullptr);  //  ��������ʹ���вι��캯�����������ݵ��½ڵ�
    ~Node();

    // ����
    void deleteNode(Node *head, int key); // ɾ���ڵ㣨��δʹ�ã�
    static Node *HeadInsert(Node *head, T item); // ͷ�巨
    static Node *TailInsert(Node *head, T item); // β�巨

};
