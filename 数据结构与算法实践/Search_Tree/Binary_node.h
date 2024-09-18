//
// Created by Deralive (10235101526) on 2024/6/8.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//
#ifndef BINARY_NODE_H
#define BINARY_NODE_H

template <class Entry>
class Binary_node
{
public:
    // data members:
    Entry data;                // data component
    Binary_node<Entry> *left;  // children
    Binary_node<Entry> *right; // children

    // constructors:
    Binary_node(); // default constructor

    Binary_node(const Entry &x); // constructor with data

    void set_balance(int balance); // set balance factor

    int get_balance() const; // get balance factor

private:
    int balance_factor; // balance factor
};

#endif
