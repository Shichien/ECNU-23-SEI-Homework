//
// Created by Deralive (10235101526) on 2024/05/08.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "move.h"

Move::Move()
/* Post: The Move is initialized to an illegal, default value. */
{
    row = 3;
    col = 3;
}
Move::Move(int r, int c)
/* Post: The Move is initialized to the given coordinates. */
{
    row = r;
    col = c;
}
