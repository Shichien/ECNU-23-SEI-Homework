//
// Created by Deralive (10235101526) on 2024/4/11.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Polynomial.cpp"

typedef Polynomial Node_entry; // Todo: change this to Polynomial

struct Node {
    // data members
    Node_entry entry; // data
    Node* next; // link
    // constructors
    Node();
    Node(Node_entry item, Node* add_on = 0);
};