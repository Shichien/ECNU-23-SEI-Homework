//
// Created by Deralive (10235101526) on 2024/05/16.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "ListsNode.cpp"
using namespace std;

// The following functions are used to test the List class
enum Error_code
{
    underflow,
    overflow,
    Range_Error,
    success
};

template <class List_entry>
class List
{
public:
    ~List();                                                // Destructor
    List();                                                 // Default constructor
    List(const List<List_entry> &copy);                     // Copy constructor
    void operator=(const List<List_entry> &copy);           // Overload operator =
    int size() const;                                       // Get the size of the list
    bool full() const;                                      // Check if the list is full
    bool empty() const;                                     // Check if the list is empty
    void clear();                                           // Clear the list
    void traverse(void (*visit)(List_entry &));             // Traverse the list
    Error_code retrieve(int position, List_entry &x) const; // Retrieve the element at the position
    Error_code replace(int position, const List_entry &x);  // Replace the element at the position
    Error_code remove(int position, List_entry &x);         // Remove the element at the position
    Error_code insert(int position, const List_entry &x);   // Insert the element at the position

protected:
    // Data members for the linked list implementation now follow.
    int count;                         // Number of elements in the List
    mutable int current_position;      // Position of current Node
    mutable Node<List_entry> *current; // Pointer to current Node
    Node<List_entry> *head;            // Pointer to the head Node
    // The following auxiliary function is used to locate list positions
    void set_position(int position) const; // Set the position of the current Node
};
