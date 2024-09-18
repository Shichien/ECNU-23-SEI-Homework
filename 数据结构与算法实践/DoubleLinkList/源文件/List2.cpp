//
// Created by Deralive (10235101526) on 2024/05/16.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "List2.h"
#include <iostream>
using namespace std;

/*
Pre: None.
Post: The List is initialized to be empty.
*/
template <class List_entry>
List<List_entry>::List()
{
    count = 0;            // Initialize the count to 0
    head = NULL;          // Initialize the head to NULL
    current_position = 0; // Initialize the current_position to 0
    current = NULL;       // Initialize the current to NULL
}

/*
 * Pre:
 */
template <class List_entry>
void List<List_entry>::operator=(const List<List_entry> &copy)
{                                    // Overload operator =
    List_entry x;                    // Define a variable x
    if (this == &copy)               // If the list is the same as the copy
        return;                      // Return
    while (!empty())                 // While the list is not empty
        remove(0, x);                // Remove the element at position 0
    Node<List_entry> *q = copy.head; // Define a pointer q pointing to the head of the copy
    int i = 0;
    while (q)
    {
        insert(i, q->entry); // Insert the element at position i
        q = q->next;         // Move to the next element
        i++;                 // Increment i
    }
}

template <class List_entry>
void List<List_entry>::set_position(int position) const
/* Pre: position is a valid position in the List: 0 <= position < count.
 Post: The current Node pointer references the Node at position. */
{
    if (head == NULL)
    {                         // Check if the list is empty
        current = NULL;       // Ensure current is NULL
        current_position = 0; // Reset the current position
        return;               // Return as there's nothing to set
    }

    if (position < current_position || current == NULL)
    {
        // Start from the head if position is before current or current is NULL
        current = head;
        current_position = 0;
    }

    while (current_position < position && current != NULL)
    {
        current = current->next;
        current_position++;
    }

    if (current == NULL)
    {
        // If current is NULL after trying to set the position, handle the error
        throw std::runtime_error("Reached a null pointer in the list before reaching the desired position.");
    }
}

/* Post: If the List is not full and 0 <= position <= n , where n is the number of
 entries in the List , the function succeeds: Any entry formerly at position and
 all later entries have their position numbers increased by 1, and x is inserted at
 position of the List .
 Else: The function fails with a diagnostic error code. */
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
{
    if (position < 0 || position > count)
        return Range_Error;                            // Invalid position
    Node<List_entry> *new_node, *previous, *following; // Nodes to be added
    if (position > 0)
    {                               // Insert the new node
        set_position(position - 1); // Set the position to position - 1
        following = previous->next; // Set the following to the next of previous
    }
    else
        following = head;                          // Set the following to the head
    new_node = new Node<List_entry>(x, following); // Create a new node
    if (new_node == NULL)
        return overflow; // No memory
    if (position == 0)
    {
        head = new_node;      // Set the head to new_node
        current_position = 0; // Set the current_position to 0
        current = head;       // Set the current to the head
    }
    else
    {
        previous->next = new_node; // Insert the new node
        set_position(position);    // Set the position to position
    }
    count++;        // Increment the count
    return success; // Insert successfully
}

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
    if (position < 0 || position >= count)  // Invalid position
        return Range_Error;                 // Invalid position
    Node<List_entry> *previous, *following; // Nodes to be removed
    if (position > 0)
    {
        set_position(position - 1);       // Set the position to position - 1
        following = previous->next;       // Set the following to the next of previous
        previous->next = following->next; // Set the next of previous to the next of following
    }
    else
    {
        following = head;     // Set the following to the head
        head = head->next;    // Set the head to the next of head
        current_position = 0; // Set the current_position to 0
        current = head;       // Set the current to the head
    }
    x = following->entry; // Set x to the entry of following
    delete following;     // Delete the following
    count--;              // Decrement the count
    return success;
}

template <class List_entry>
int List<List_entry>::size() const
{
    return count; // Return the count
}

template <class List_entry>
bool List<List_entry>::full() const
{
    Node<List_entry> *new_node;      // Define a new node
    new_node = new Node<List_entry>; // Create a new node
    if (new_node == NULL)            // No memory
        return true;                 // Return true
    else
    {
        delete new_node; // Delete the new node
        return false;    // Return false
    }
}

template <class List_entry>
bool List<List_entry>::empty() const
{
    return count == 0; // Return if the count is 0
}

template <class List_entry>
void List<List_entry>::clear()
{
    List_entry x;
    while (!empty()) // While the list is not empty
        remove(0, x);
}

template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &))
{
    Node<List_entry> *p_node = head; // Define a pointer p_node pointing to the head
    while (p_node)
    {
        (*visit)(p_node->entry); // Visit the entry of p_node
        p_node = p_node->next;   // Move to the next element
    }
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
{
    if (position < 0 || position >= count) // Invalid position
        return Range_Error;
    Node<List_entry> *p_node; // Define a pointer p_node
    set_position(position);   // Set the position to position
    x = current->entry;       // Set x to the entry of current
    return success;           // Retrieve successfully
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
{
    if (position < 0 || position >= count) // Invalid position
        return Range_Error;                // Invalid position
    Node<List_entry> *p_node;              // Define a pointer p_node
    p_node = set_position(position);       // Set the position to position
    p_node->entry = x;                     // Set the entry of p_node to x
    return success;                        // Replace successfully
}

template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy)
{
    count = 0;                       // Initialize the count to 0
    head = NULL;                     // Initialize the head to NULL
    Node<List_entry> *q = copy.head; // Define a pointer q pointing to the head of the copy
    int i = 0;
    while (q)
    {
        insert(i, q->entry); // Insert the element at position i
        q = q->next;         // Move to the next element
        i++;
    }
}

template <class List_entry>
List<List_entry>::~List()
{
    List_entry x;
    while (!empty()) // While the list is not empty
        remove(0, x);
}

template <class List_entry>
void update(List_entry &x)
{
    x *= 2; // Multiply x by 2
}

template <class List_entry>
void print(List_entry &x)
{
    cout << x << endl; // Output x
}
