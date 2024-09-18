#include "Record.cpp"

enum Error_code
{
    not_present,
    overflow,
    duplicate_error,
    success
};
const int hash_size = 97;
class Hash_table
{
public:
    void clear();                                                // Clear the hash table
    Error_code insert(const Record &new_entry);                  // Insert a record
    Error_code retrieve(const Key &target, Record &found) const; // Retrieve a record
    Error_code remove(const Key &target, Record &found);         // Remove a record

private:
    Record table[hash_size]; // Hash table
};
int hash(const Record &new_entry); // Hash function
int hash(const Key &new_entry);    // Hash function
