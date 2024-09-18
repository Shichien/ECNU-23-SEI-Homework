//
// Created by Deralive (10235101526) on 2024/05/16.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>

template <class Node_entry>
struct Node
{
    // data members
    Node_entry entry;       // data in the node
    Node<Node_entry> *next; // link to the next node
    // constructors
    Node();                                                 // default constructor
    Node(Node_entry item, Node<Node_entry> *add_on = NULL); // constructor with parameters
};