//
// Created by Deralive (10235101526) on 2024/06/04.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Key.cpp"

class Record
{
public:
    operator Key();               // implicit conversion from Record to Key .
    Record(int x = 0, int y = 0); // Constructor
    int the_key() const;          // Return the key
    int the_other() const;        // Return the record

private:
    int key;
    int other;
};

bool operator!=(const Record &x, const Record &y); // Compare two records
bool operator==(const Record &x, const Record &y); // Compare two records
