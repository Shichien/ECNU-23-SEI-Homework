//
// Created by Deralive (10235101526) on 2024/03/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "SmallNode.cpp"

typedef Term Queue_entry;

enum Queue_Error_code {
    success,
    overflow,
    underflow,
};

class Queue {
public:
    // standard Queue methods
    Queue();   // constructor
    ~Queue();    // safety features for linked structures

    bool empty() const;

    Queue_Error_code append(const Queue_entry& item); // add an item to the rear of the queue
    Queue_Error_code serve();   // remove the front item from the queue
    Queue_Error_code retrieve(Queue_entry& item) const; // retrieve the front item from the queue


protected:
    SmallNode* front, * rear;  // pointers to the front and rear of the queue
};