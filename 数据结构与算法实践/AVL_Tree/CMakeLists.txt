cmake_minimum_required(VERSION 3.28)
project(AVL_Tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AVL_Tree
        AVL_Node.cpp
        AVL_Node.h
        AVL_Tree.cpp
        AVL_Tree.h
        Binary_node.cpp
        Binary_node.h
        Binary_tree.cpp
        Binary_tree.h
        main.cpp
        Node.cpp
        Node.h
        Record.cpp
        Record.h
        Search_tree.cpp
        Search_tree.h
        Stack.cpp
        Stack.h)
