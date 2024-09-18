//
// Created by Deralive (10235101526) on 2024/06/04.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Record.cpp"
#include "List.cpp"

const int hash_size = 97; // Small prime number

enum Error_code // Error codes for hash table
{
    not_present,
    Overflow,
    duplicate_error,
    Success
};

class Hash_table // Hash table class
{
public:
    void clear();                                                // Clear the hash table
    Error_code insert(const Record &new_entry);                  // Insert a record
    Error_code retrieve(const Key &target, Record &found) const; // Retrieve a record
    Error_code remove(const Key &target, Record &found);         // Remove a record

private:
    List<Record> table[hash_size]; // Hash table
};

int hash(const Record &new_entry); // Hash function
int hash(const Key &new_entry);    // Hash function
