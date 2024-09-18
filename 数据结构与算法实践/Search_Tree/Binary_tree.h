//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Binary_node.cpp"
#include "Stack.cpp"

template <class Entry>
class Binary_tree
{
public:
    Binary_tree(); // Constructor

    bool empty() const; // Return true if the binary tree is empty; otherwise, return false.

    void preorder(void (*visit)(Entry &)); // Traverse the binary tree in preorder.

    void inorder(void (*visit)(Entry &)); // Traverse the binary tree in inorder.

    void postorder(void (*visit)(Entry &)); // Traverse the binary tree in postorder.

    int size() const; // Return the number of nodes in the binary tree.

    int height() const; // Return the height of the binary tree.

    void insert(Entry &); // Insert a new node into the binary tree.

protected:
    // Add auxiliary function prototypes here.
    void recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)); // Traverse the binary tree in preorder recursively.

    void recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)); // Traverse the binary tree in inorder recursively.

    void recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)); // Traverse the binary tree in postorder recursively.

    Binary_node<Entry> *root;
    int count;
};

#endif
