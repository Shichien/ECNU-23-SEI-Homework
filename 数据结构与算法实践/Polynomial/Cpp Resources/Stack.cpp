//
// Projected By Deralive (10235101526), release on 08/03/2024
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Stack.h"

/*
* Pre : None.
* Post: Initialize The Stack.
*/
Stack::Stack() {
    top_node = nullptr;
    /* Node<T>* top_node 在构造函数中被声明为局部变量，而不是作为类成员变量
    * 构造函数结束后，top_node 就会被销毁
    * 若类的其他成员函数仍然试图访问它，会导致 Segmentation Fault
    * 在构造函数中不要重新声明（Node<T>* top_node，直接对类成员变量 top_node 赋初始值即可
    */
}

/*
* Pre : The Stack Is Already Initialized.
* Post: Check The Stack Is Empty Or Not.
*/
bool Stack::empty() const {
    return (top_node == nullptr);
}

/*
* Pre : The Stack Is Already Initialized, Less Than Stack's Maxsize.
* Post: Push The Item Into The Stack.
*/
Error_code Stack::push(const Node_entry& item) {
    Node* new_top = new Node(item, top_node);
    if (new_top == nullptr) {
        return Overflow; // 新头指针若为空，说明创建失败
        // cout << "The stack is overflow" << endl;
    }
    top_node = new_top; // 头指针指向新加入的元素
    return Success;
}

/*
* Pre : The Stack Is Already Initialized, And At Lease One Item.
* Post: Pop The Top Item In The Stack.
*/
Error_code Stack::pop() {
    if (top_node == nullptr) {
        return Underflow;
    }
    else {
        Node* old_top = top_node; // 头指针变成原来头指针指向的下一个节点
        top_node = old_top->next;
        delete old_top; // 删除原头部的指针，模拟元素被删除
        return Success;
    }
}

/*
* Pre : The Stack Is Already Initialized.
* Post: Output The Top Item In The Stack To User.
*/
Error_code Stack::top(Node_entry& item) const {
    if (top_node == nullptr) {
        // cout << "The stack is underflow!" << endl;
        return Underflow;
    }
    item = top_node->entry; // 读取的数据为此时头指针指向的数据
    return Success;
}

// Safety features for linked structures
/*
* Pre : The Stack object exists.
* Post: All elements in the stack are removed, and memory associated with each node is deallocated.
*/
Stack::~Stack() {
    // 对象被销毁时，所有栈元素都会被清理掉.
    // 不会造成内存泄漏，在对象生命周期结束时清理对象所占用的资源.
    while (!empty()) {
        pop();
    }
}