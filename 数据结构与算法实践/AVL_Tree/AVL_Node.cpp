//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "AVL_Node.h"
#include <iostream>

using namespace std;

template <class Record>
AVL_node<Record>::AVL_node()
{
    this->left = nullptr;   // Initialize the left and right pointers to null.
    this->right = nullptr;  // Initialize the left and right pointers to null.
    balance = equal_height; // Initialize the balance factor to equal_height.
}

template <class Record>
AVL_node<Record>::AVL_node(const Record &x)
{
    this->data = x;        // Initialize the data field to x.
    this->left = nullptr;  // Initialize the left and right pointers to null.
    this->right = nullptr; // Initialize the left and right pointers to null.
    balance = equal_height;
}

template <class Record>
void AVL_node<Record>::set_balance(Balance_factor b)
{
    balance = b;
} // Set the balance factor to b.

template <class Record>
Balance_factor AVL_node<Record>::get_balance() const
{
    return balance; // Return the balance factor.
}
