//
// Created by Deralive (10235101526) on 2024/06/04.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Record.h"

Record::Record(int x, int y)
{
    key = x;   // Initialize the key
    other = y; // Initialize the record
}
int Record::the_key() const
{
    return key; // Return the key
}
int Record::the_other() const
{
    return other; // Return the record
}

Record::operator Key()
{
    Key tmp(key); // Create a key
    return tmp;   // Return the key
}
bool operator!=(const Record &x, const Record &y)

{
    return x.the_key() != y.the_key(); // Return the comparison
}
bool operator==(const Record &x, const Record &y)

{
    return x.the_key() == y.the_key(); // Return the comparison
}
