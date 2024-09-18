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
    T data; //  保存该节点的数据
    Node *next; //  保存下一个节点的地址

    // 构造函数与析构函数
    Node();     //  在初始化时，可以用此无参构造函数创建空节点
    Node(T item, Node *add_on = nullptr);  //  后续可以使用有参构造函数创建带数据的新节点
    ~Node();

    // 方法
    void deleteNode(Node *head, int key); // 删除节点（暂未使用）
    static Node *HeadInsert(Node *head, T item); // 头插法
    static Node *TailInsert(Node *head, T item); // 尾插法

};
