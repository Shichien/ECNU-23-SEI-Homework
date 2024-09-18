//
// Created by Deralive (10235101526) on 2024/05/16.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "List1.h"
#include <iostream>
using namespace std;

template <class List_entry>
List<List_entry>::List()
/* Pre: None.
   Post: The List is initialized to be empty. The head pointer is set to NULL and count is set to 0. */
{
    count = 0;
    head = NULL;
}

/* Pre: The List exists.
   Post: Deep copies all the elements from the List 'copy' to this List.
   If the List is initially non-empty, it is cleared first.
*/
template <class List_entry>
void List<List_entry>::operator=(const List<List_entry> &copy)
{
    List_entry x;
    if (this == &copy) // If the list is the same as the copy
        return;
    while (!empty()) // While the list is not empty
        remove(0, x);
    Node<List_entry> *q = copy.head; // Define a pointer q pointing to the head of the copy
    int i = 0;
    while (q)
    {
        insert(i, q->entry); // Insert the element at position i
        q = q->next;         // Move to the next element
        i++;
    }
}

/* Pre: position is a valid position in the List ;
0 <= position < count .
Post: Returns a pointer to the Node inposition.
*/
template <class List_entry>
Node<List_entry> *List<List_entry>::set_position(int position) const
{
    Node<List_entry> *q = head;
    for (int i = 0; i < position; i++) // Loop until i is equal to position
        q = q->next;                   // Move to the next element
    return q;
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
    {
        previous = set_position(position - 1); // Set the previous to the position - 1
        following = previous->next;            // Set the following to the next of previous
    }
    else
        following = head;                          // Set the following to the head
    new_node = new Node<List_entry>(x, following); // Create a new node
    if (new_node == NULL)                          // No memory
        return overflow;
    if (position == 0)
        head = new_node;
    else
        previous->next = new_node; // Insert the new node
    count++;                       // Increment the count
    return success;
}

/* Pre: The position is valid, i.e., 0 <= position < count.
   Post: Removes the entry at position, returning it in x.
   All entries beyond position are shifted left. The count is decremented by 1.
*/
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
    if (position < 0 || position >= count)  // Invalid position
        return Range_Error;                 // Invalid position
    Node<List_entry> *previous, *following; // Nodes to be removed
    if (position > 0)
    {
        previous = set_position(position - 1); // Set the previous to the position - 1
        following = previous->next;            // Set the following to the next of previous
        previous->next = following->next;      // Remove the element
    }
    else
    {
        following = head;  // Set the following to the head
        head = head->next; // Remove the element
    }
    x = following->entry; // Set the x to the entry of following
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
        return true;
    else
    {
        delete new_node; // Delete the new node
        return false;
    }
}

/*
Pre: None.
Post: Returns true if the List is empty; otherwise, returns false.
*/
template <class List_entry>
bool List<List_entry>::empty() const
{
    return count == 0; // Return if the count is 0
}

/*
Pre: None.
Post: Clear the List.
*/
template <class List_entry>
void List<List_entry>::clear()
{
    List_entry x;
    while (!empty()) // While the list is not empty
        remove(0, x);
}

/*
Pre: None.
Post: Traverse the List.
*/
template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &))
{
    Node<List_entry> *p_node = head; // Define a pointer p_node pointing to the head
    while (p_node)
    {
        (*visit)(p_node->entry); // Visit the element
        p_node = p_node->next;   // Move to the next element
    }
}

/* Pre: The position is valid, i.e., 0 <= position < count.
   Post: Retrieves the entry at position, returning it in x.
*/
template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
{
    if (position < 0 || position >= count) // Invalid position
        return Range_Error;                // Invalid position
    Node<List_entry> *p_node;              // Define a pointer p_node
    p_node = set_position(position);       // Set the position of p_node
    x = p_node->entry;                     // Set x to the entry of p_node
    return success;                        // Retrieve successfully
}

/* Pre: The position is valid, i.e., 0 <= position < count.
   Post: Replaces the entry at position with x.
*/
template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
{
    if (position < 0 || position >= count) // Invalid position
        return Range_Error;                // Invalid position
    Node<List_entry> *p_node;              // Define a pointer p_node
    p_node = set_position(position);       // Set the position of p_node
    p_node->entry = x;                     // Set the entry of p_node to x
    return success;
}

template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy)
{
    count = 0;
    head = NULL;
    Node<List_entry> *q = copy.head; // Define a pointer q pointing to the head of the copy
    int i = 0;
    while (q)
    {
        insert(i, q->entry); // Insert the element at position i
        q = q->next;
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
