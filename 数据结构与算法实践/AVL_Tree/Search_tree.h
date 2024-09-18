//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

#include "Binary_tree.cpp"

enum Search_tree_errors // Error codes for search tree operations.
{
    success,
    not_present,
    duplicate_error
};

template <class Record>
class Search_tree : public Binary_tree<Record> // A search tree class.
{
public:
    Search_tree_errors insert(const Record &new_data); // Add new_data to the tree.

    Search_tree_errors remove(const Record &target); // Remove target from the tree.

    Search_tree_errors tree_search(Record &target) const; // Set target to data in tree.

private:                                                                                             // Add auxiliary function prototypes here.
    Binary_node<Record> *search_for_node(Binary_node<Record> *sub_root, const Record &target) const; // Return pointer to node containing target.

    Search_tree_errors search_and_insert(Binary_node<Record> *&sub_root, const Record &new_data); // Add new_data to tree.

    Search_tree_errors search_and_destroy(Binary_node<Record> *&sub_root, const Record &target); // Remove target from tree.

    Search_tree_errors remove_root(Binary_node<Record> *&sub_root); // Remove root of tree.
};

#endif
