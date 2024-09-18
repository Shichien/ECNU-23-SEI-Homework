//
// Created by Deralive (10235101526) on 2024/06/04.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "Hash_Table2.cpp"
using namespace std;

int main()
{
    Hash_table myhash;               // Create a hash table
    myhash.insert(Record(3, 20));    // Insert a record
    myhash.insert(Record(5, 30));    // Insert a record
    myhash.insert(Record(9, 50));    // Insert a record
    Record target;                   // Create a record
    myhash.retrieve(Key(5), target); // Retrieve
    cout << "Key: " << target.the_key() << " The other: " << target.the_other() << endl;

    target = Record(0, 0);           // Create a record
    myhash.retrieve(Key(3), target); // Retrieve
    cout << "Key: " << target.the_key() << " The other: " << target.the_other() << endl;

    target = Record(0, 0);         // Create a record
    myhash.remove(Key(3), target); // Remove
    cout << "Key: " << target.the_key() << " The other: " << target.the_other() << endl;

    target = Record(0, 0);           // Create a record
    myhash.retrieve(Key(3), target); // Retrieve
    cout << "Key: " << target.the_key() << " The other: " << target.the_other() << endl;

    cin.get();
}
