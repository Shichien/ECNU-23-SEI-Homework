//
// Created by Deralive (10235101526) on 2024/06/04.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Key.h"

Key::Key(int x)
{
    key = x; // Initialize the key
}
int Key::the_key() const
{
    return key; // Return the key
}
bool operator==(const Key &x, const Key &y)

{
    return x.the_key() == y.the_key(); // Return the comparison
}
