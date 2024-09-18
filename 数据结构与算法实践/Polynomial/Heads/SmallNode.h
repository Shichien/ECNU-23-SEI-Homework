//
// Created by Deralive (10235101526) on 2024/04/24.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Term.cpp"

typedef Term SmallNode_entry;

class SmallNode {
    // data members
public:
    SmallNode_entry entry;  // data
    SmallNode* next;       // link
    // constructors
    SmallNode();
    SmallNode(SmallNode_entry item, SmallNode* add_on = 0);
};