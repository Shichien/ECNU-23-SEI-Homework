//
// Created by Deralive (10235101526) on 2024/4/18.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include<iostream>
#include"Queue.cpp"

// 对于模板类，继承时也要显式地展现模板
// 不使用模板类的时候：class Extended_Queue : public Queue {

template<class T>
class Extended_Queue : public Queue<T> {
public:
    int size() const; // 链队列的大小分析
    void clear();   // 清空链队列
    State serve_and_retrieve(T& item); // 获取最前端的元素后，删除它.
};