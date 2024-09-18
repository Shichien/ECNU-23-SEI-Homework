//
// Created by Deralive (10235101526) on 2024/03/23.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include"MyQueue.h"

/*
* Pre : None.
* Post: Initialize The Queue (Constructor Function).
*/
MyQueue::MyQueue() {
    count = 0;
    rear = maxqueue - 1;
    front = 0;
}

/*
* Pre : None.
* Post: Check the queue is empty or not.
*/
bool MyQueue::empty() const {
    return count == 0;
}

/*
* Pre : The Queue Is Already Initialized.
* Post: Insert An Element Into The Queue.
*/
Error_code MyQueue::append(const Queue_entry &item) {
    if (count >= maxqueue) return overflow;
    count++;
    rear = (rear + 1) % maxqueue;
    entry[rear] = item;
    return success;
}

/*
* Pre : The Queue Isn't Empty.
* Post: Output The Element With Removing It From The Queue.
*/
Error_code MyQueue::serve() {
    if (count <= 0) return underflow;
    count--;
    front = (front + 1) % maxqueue;
    return success;
}

/*
* Pre : At Least One Element In The Queue.
* Post: Output The Element Without Removing It From The Queue.
*/
Error_code MyQueue::retrieve(Queue_entry &item) const {
    if (count <= 0) return underflow;
    item = entry[front];
    return success;
}

/*
* Pre : None.
* Post: Return The Size Of The Queue.
*/
int MyQueue::size() const {
    return count;
}

/*
* Pre : None.
* Post: Check The Queue Is Full Or Not.
*/
bool MyQueue::full() const {
    return (count == maxqueue);
}

/*
* Pre : None.
* Post: Clear All Elements In The Queue.
*/
void MyQueue::clear() {
    count = 0;
    rear = maxqueue - 1;
    front = 0;
}

/*
* Pre : At Least One Element In The Queue.
* Post: retrieving And Serve The Element From The Queue.
*/
Error_code MyQueue::serve_and_retrieve(Queue_entry &item) {
    if (count <= 0) return underflow;
    item = entry[front];
    count--;
    front = (front + 1) % maxqueue;
    return success;;
}
