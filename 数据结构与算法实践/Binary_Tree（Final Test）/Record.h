//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>

using namespace std;

class Record
{
public:
    Record();                 // default constructor
    Record(int x, int y = 0); // constructor
    int the_key() const;      // accessor

private:
    int key;   // key field
    int other; // other field

    friend bool operator>(const Record &x, const Record &y);      // comparison operators
    friend bool operator<(const Record &x, const Record &y);      // comparison operators
    friend bool operator>=(const Record &x, const Record &y);     // comparison operators
    friend bool operator<=(const Record &x, const Record &y);     // comparison operators
    friend bool operator==(const Record &x, const Record &y);     // comparison operators
    friend bool operator!=(const Record &x, const Record &y);     // comparison operators
    friend ostream &operator<<(ostream &output, Record &x);       // output operator
    friend ostream &operator<<(ostream &output, const Record &x); // output operator
};
