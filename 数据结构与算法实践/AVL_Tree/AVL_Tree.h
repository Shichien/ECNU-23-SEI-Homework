//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "Search_tree.cpp"
#include "AVL_Node.cpp"

enum AVL_Error
{
    AVL_success,
    AVL_not_present,
    AVL_duplicate_error,
    overflow,
    underflow
};

template <class Record>
class AVL_tree : public Search_tree<Record>
{
public:
    AVL_Error insert(const Record &new_data); // Add new_data to the tree.

    AVL_Error remove(Record &old_data); // Remove old_data from the tree.

private:                                                                                        // Add auxiliary function prototypes here.
    AVL_Error avl_insert(Binary_node<Record> *&sub_root, const Record &new_data, bool &taller); // Add new_data to tree.

    void rotate_left(Binary_node<Record> *&sub_root); // Rotate left.

    void rotate_right(Binary_node<Record> *&sub_root); // Rotate right.

    void right_balance(Binary_node<Record> *&sub_root); // Right balance.

    void left_balance(Binary_node<Record> *&sub_root); // Left balance.

    // add for remove
    AVL_Error avl_remove(Binary_node<Record> *&sub_root, Record &new_data, bool &shorter); // Remove new_data from tree.

    bool right_balance2(Binary_node<Record> *&sub_root); // Right balance.

    bool left_balance2(Binary_node<Record> *&sub_root); // Left balance.
};

#endif