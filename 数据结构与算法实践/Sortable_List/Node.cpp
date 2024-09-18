//
// Created by Deralive (10235101526) on 2024/05/16.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Node.h"
#include <iostream>

/*
Pre: None.
Post: The Node is initialized with next pointing to NULL.
*/
template <class Node_entry>
Node<Node_entry>::Node()
{
    next = NULL; // Set the next to NULL
}

/*
Pre: None.
Post: The Node is initialized with entry set to item and next set to add_on.
*/
template <class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node<Node_entry> *add_on)
{
    entry = item;  // Set the entry to item
    next = add_on; // Set the next to add_on
}