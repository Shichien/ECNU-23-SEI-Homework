//
// Created by Deralive (10235101526) on 2024/4/11.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

// redefinition of 'class Node<T>' ˵���������ظ�#include""�������Ҫע����
template<class T>
class Node {
public:
    Node(); // Ĭ�Ϲ��캯��
    Node(T item, Node* add_on = nullptr); // ���������ṩ��Ĭ�ϲ�������Node.cpp�������ٴ�����

    T data; // ������
    Node* next; // ָ����
};
