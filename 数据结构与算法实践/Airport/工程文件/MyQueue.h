//
// Created by Deralive (10235101526) on 2024/03/23.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include"Plane.cpp"

enum Error_code {
    underflow, overflow, success, fail
};

const int maxqueue = 100; //  small value for testing

typedef Plane Queue_entry;


class MyQueue {

public:

    MyQueue();  // 构造函数

    bool empty() const; //检测队列是否为空

    Error_code serve(); //  从队列中取出一个元素，并移除该元素

    Error_code append(const Queue_entry &item); //  向队列中插入一个元素

    Error_code retrieve(Queue_entry &item) const;   //    从队列中输出顶部元素并输出到屏幕上，但不移除该元素

    bool full() const;  // 检测队列是否已满

    int size() const;   // 显示队列中已有的元素个数

    void clear();   //  清除队列中的所有元素，恢复为初始状态

    Error_code serve_and_retrieve(Queue_entry &item);   //    从队列中输出顶部元素并输出到屏幕上，并移除该元素

protected:

    int count;

    int front, rear;

    Queue_entry entry[maxqueue];

};