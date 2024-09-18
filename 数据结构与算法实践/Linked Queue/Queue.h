//
// Created by Deralive (10235101526) on 2024/3/19.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Node.cpp"

#define MaxSize 100

enum State {
    Success,
    Overflow,
    Underflow,
};

template<class T>
class Queue {
public:

    // standard Queue methods
    Queue();    // 构造函数
    Queue(const Queue& original); // 带参数的构造函数

    bool empty() const;
    State append(const T& item); //  向队列中插入一个元素
    State serve(); //  从队列中取出一个元素，并移除该元素
    State retrieve(T& item) const;   //    从队列中输出顶部元素并输出到屏幕上，但不移除该元素
    void operator = (const Queue& original);

    // safety features for linked structures
    ~Queue();

protected:
    Node<T>* front;
    Node<T>* rear;
};