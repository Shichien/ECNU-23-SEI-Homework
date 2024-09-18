//
// Created by Deralive (10235101526) on 2024/04/24.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "SmallNode.h"

/*
* Pre : When the object is created.
* Post: The initialization header pointer is grounded, indicating that there are no elements in the stack at this time.
*/
SmallNode::SmallNode() {
    next = 0;
}

/*
* Pre : When the object is created.
* Post: A new node is created, passing in data and a pointer to the next node
*/
SmallNode::SmallNode(SmallNode_entry item, SmallNode* add_on) {
    entry = item; // 传入数据
    next = add_on; // 以及提供新的指向新节点的指针
}