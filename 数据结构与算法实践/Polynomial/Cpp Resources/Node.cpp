//
// Created by Deralive (10235101526) on 2024/4/11.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Node.h"

/*
* Pre : When the object is created.
* Post: The initialization header pointer is grounded, indicating that there are no elements in the stack at this time.
*/
Node::Node() {
    next = nullptr;
}

/*
* Pre : When the object is created.
* Post: A new node is created, passing in data and a pointer to the next node
*/
Node::Node(Node_entry item, Node* add_on) {
    entry = item;
    next = add_on;
}