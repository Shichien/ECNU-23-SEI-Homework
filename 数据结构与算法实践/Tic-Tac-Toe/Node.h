//
// Created by Deralive (10235101526) on 2024/4/11.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

// redefinition of 'class Node<T>' 说明出现了重复#include""的情况，要注意检查
template<class T>
class Node {
public:
    Node(); // 默认构造函数
    Node(T item, Node* add_on = nullptr); // 在声明中提供了默认参数，在Node.cpp中无需再次声明

    T data; // 数据域
    Node* next; // 指针域
};
