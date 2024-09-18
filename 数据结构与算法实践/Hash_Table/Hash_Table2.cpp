//
// Created by Deralive (10235101526) on 2024/06/04.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Hash_Table2.h"

void Hash_table ::clear() // Clear the hash table
/* Post: The hash table is cleared.*/
{
    for (int i = 0; i < hash_size; i++) // For each list
    {
        table[i].clear(); // Clear each list
    }
}

int hash(const Record &new_entry)
/* Post: The function returns the hash value of the key of new_entry.*/
{
    return new_entry.the_key() % hash_size; // Hash function
}

int hash(const Key &new_entry)
/* Post: The function returns the hash value of the key of new_entry.*/
{
    return new_entry.the_key() % hash_size; // Hash function
}

Error_code Hash_table ::insert(const Record &new_entry)
/* Post: If the table is not full and new_entry is not already in the table,
new_entry is inserted into the table and success is returned;
otherwise, an appropriate error code is returned.*/
{
    int probe;
    probe = hash(new_entry);                      // Hash the key
    for (int i = 0; i < table[probe].size(); i++) // For each record in the list
    {
        Record tmp;                    // Create a record
        table[probe].retrieve(i, tmp); // Retrieve the record
        if (tmp == new_entry)          // If the record is the same
            return duplicate_error;    // Return duplicate error
    }
    table[probe].insert(0, new_entry); // Insert the record
    return Success;
}

Error_code Hash_table ::retrieve(const Key &target, Record &found) const
/* Post: If a record with a key matching that of target is in the table,
then found is set to that record and success is returned;*/
{
    int probe;                                    // Create a probe
    probe = hash(target);                         // Hash the key
    for (int i = 0; i < table[probe].size(); i++) // For each record in the list
    {
        Record tmp;                    // Create a record
        table[probe].retrieve(i, tmp); // Retrieve the record
        if (target == tmp)             // If the record is the same
        {
            found = tmp;    // Set the found record
            return Success; // Return success
        }
    }
    return not_present; // Return not present
}

Error_code Hash_table ::remove(const Key &target, Record &found) // Remove a record
/* Post: If a record with a key matching that of target is in the table,
then that record is removed from the table and success is returned;
otherwise, an appropriate error code is returned.*/
{
    int probe;                                    // Create a probe
    probe = hash(target);                         // Hash the key
    for (int i = 0; i < table[probe].size(); i++) // For each record in the list
    {
        Record tmp;                    // Create a record
        table[probe].retrieve(i, tmp); // Retrieve the record
        if (target == tmp)             // If the record is the same
        {
            table[probe].remove(i, found); // Remove the record
            return Success;                // Return success
        }
    }
    return not_present; // Return not present
}