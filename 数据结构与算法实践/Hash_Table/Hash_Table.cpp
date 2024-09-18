//
// Created by Deralive (10235101526) on 2024/06/04.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Hash_Table.h"

void Hash_table::clear()
/*Post: The hash table is initialized to be empty.*/
{
    for (int i = 0; i < hash_size; i++)
    {
        Record tmp;     // Create a record
        table[i] = tmp; // Clear each list
    }
}

int hash(const Record &new_entry)
/*Post: The function returns the hash value of the key of new_entry.*/
{
    return new_entry.the_key() % hash_size; // Hash function
}

int hash(const Key &new_entry)
/*Post: The function returns the hash value of the key of new_entry.*/
{
    return new_entry.the_key() % hash_size; // Hash function
}

Error_code Hash_table::insert(const Record &new_entry)
/*Post: If the table is not full and new_entry is not already in the table,
new_entry is inserted into the table and success is returned;
otherwise, an appropriate error code is returned.*/
{
    Error_code result = success;
    int probe_count,         // Counter to be sure that table is not full.
        increment,           // Increment used for quadratic probing.
        probe;               // Position currently probed in the hash table.
    probe = hash(new_entry); // Compute initial probe position.
    probe_count = 0;         // Prepare for the worst.
    increment = 1;           // Prepare increment for next iteration.
    Record found;            // Use to retrieve the record if it is already in the table.
    if (retrieve(new_entry.the_key(), found) == success)
        return duplicate_error;
    while (table[probe].the_key() != 0     // Is the location empty?
           && table[probe].the_key() != -1 // empty because delete
           && probe_count < (hash_size + 1) / 2)
    {                                            // Has overflow occurred?
        probe_count++;                           // Count the probe.
        probe = (probe + increment) % hash_size; // Move probe position.
        increment += 2;                          // Prepare increment for next iteration.
    }
    if (table[probe].the_key() == 0 || table[probe].the_key() == -1) // Is the location available?
        table[probe] = new_entry;                                    // Insert the record.
    else
        result = overflow; // The table is full.
    return result;
}

Error_code Hash_table::retrieve(const Key &target, Record &found) const
/*Post: If a record with a key matching that of target is in the table,
then found is set to that record and success is returned;*/
{
    int probe_count,                                     // Counter to be sure that table is not full.
        increment,                                       // Increment used for quadratic probing.
        probe;                                           // Position currently probed in the hash table.
    probe = hash(target);                                // Compute initial probe position.
    probe_count = 0;                                     // Prepare for the worst.
    increment = 1;                                       // Prepare increment for next iteration.
    while (table[probe].the_key() != 0                   // Is the location empty?
           && table[probe].the_key() != target.the_key() // not found
           && probe_count < (hash_size + 1) / 2)
    { // Has overflow occurred?
        probe_count++;
        probe = (probe + increment) % hash_size;
        increment += 2; // Prepare increment for next iteration.
    }
    if (table[probe].the_key() == target.the_key())
    {                         // Found the target
        found = table[probe]; // Found the target
        return success;       // Return success
    }
    else
        return not_present;
}

Error_code Hash_table::remove(const Key &target, Record &found)
/*Post: If a record with a key matching that of target is in the table,
then that record is removed from the table, found is set to that record,
and success is returned; otherwise, not_present is returned.*/
{
    int probe_count,                                     // Counter to be sure that table is not full.
        increment,                                       // Increment used for quadratic probing.
        probe;                                           // Position currently probed in the hash table.
    probe = hash(target);                                // Compute initial probe position.
    probe_count = 0;                                     // Prepare for the worst.
    increment = 1;                                       // Prepare increment for next iteration.
    while (table[probe].the_key() != 0                   // Is the location empty?
           && table[probe].the_key() != target.the_key() // not found
           && probe_count < (hash_size + 1) / 2)
    { // Has overflow occurred?
        probe_count++;
        probe = (probe + increment) % hash_size;
        increment += 2; // Prepare increment for next iteration.
    }
    if (table[probe].the_key() == target.the_key())
    {
        found = table[probe];      // Found the target
        table[probe] = Record(-1); // Mark as deleted
        return success;
    }
    else
        return not_present; // Not found
}
