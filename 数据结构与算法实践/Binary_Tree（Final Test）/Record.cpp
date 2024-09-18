//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Record.h"
#include <iostream>

using namespace std;

Record::Record()
{
    key = 0; // default constructor
    other = 0;
}

Record::Record(int x, int y)
{
    key = x; // constructor
    other = y;
}

int Record::the_key() const
{
    return key; // accessor
}

bool operator>(const Record &x, const Record &y)
{
    return x.the_key() > y.the_key(); // comparison operators
}

bool operator<(const Record &x, const Record &y)
{
    return x.the_key() < y.the_key(); // comparison operators
}

bool operator>=(const Record &x, const Record &y)
{
    return x.the_key() >= y.the_key(); // comparison operators
}

bool operator<=(const Record &x, const Record &y)
{
    return x.the_key() <= y.the_key(); // comparison operators
}

bool operator==(const Record &x, const Record &y)
{
    return x.the_key() == y.the_key(); // comparison operators
}

bool operator!=(const Record &x, const Record &y)
{
    return x.the_key() != y.the_key(); // comparison operators
}

ostream &operator<<(ostream &output, Record &x)
{
    output << x.the_key(); // output operator
    output << " ";         // output operator
    return output;
}

ostream &operator<<(ostream &output, const Record &x)
{
    output << x.the_key(); // output operator
    output << " ";         // output operator
    return output;
}
