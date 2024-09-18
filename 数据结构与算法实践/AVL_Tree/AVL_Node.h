//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#ifndef AVL_NODE_H
#define AVL_NODE_H

enum Balance_factor // Balance factor for AVL trees
{
    left_higher,
    equal_height,
    right_higher
};

template <class Record>
class AVL_node : public Binary_node<Record> // AVL node definition
{
public:
    // additional data member:
    Balance_factor balance; // balance factor

    // constructors:
    AVL_node(); // default constructor

    AVL_node(const Record &x); // constructor with data

    // overridden virtual functions:
    void set_balance(Balance_factor b); // set balance factor

    Balance_factor get_balance() const; // get balance factor
};

#endif