//
// Created by Deralive (10235101526) on 2024/6/8.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Binary_node.h"
#include <iostream>

template <class Entry>
Binary_node<Entry>::Binary_node()
{
    left = NULL;  //  left and right are pointers to the left and right children of the node.
    right = NULL; //  left and right are pointers to the left and right children of the node.
}

template <class Entry>
Binary_node<Entry>::Binary_node(const Entry &x)
{
    data = x;     //  data is the data in the node.
    left = NULL;  //  left and right are pointers to the left and right children of the node.
    right = NULL; //  left and right are pointers to the left and right children of the node.
}

template <class Entry>
void Binary_node<Entry>::set_balance(int balance)
{
    balance_factor = balance; //  balance_factor is the balance factor of the node.
}

template <class Entry>
int Binary_node<Entry>::get_balance() const
{
    return balance_factor; //  balance_factor is the balance factor of the node.
}
