//
// Created by Deralive (10235101526) on 2024/05/16.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Lists.h"

/* Pre: position is a valid position in the List : 0 <= position < count .
 Post: The current Node pointer references the Node at position . */
template <class List_entry>
void List<List_entry>::set_position(int position) const
{
    if (current_position <= position)                            // Move forward from current position
        for (; current_position != position; current_position++) // Move the pointer forward
            current = current->next;                             // Move the pointer forward
    else
        for (; current_position != position; current_position--) // Move the pointer backward
            current = current->back;                             // Move the pointer backward
}

/* Post: If the List is not full and 0 <= position <= n , where n is the number of
 entries in the List , the function succeeds: Any entry formerly at position and
 all later entries have their position numbers increased by 1, and x is inserted at
 position of the List .

 Else: The function fails with a diagnostic error code. */
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
{
    if (position < 0 || position > count) // Invalid position
        return Range_Error;

    Node<List_entry> *new_node = new Node<List_entry>(x); // Create a new node
    Node<List_entry> *following, *preceding;              // Nodes to be inserted

    if (position == 0)
    {
        following = head; // Set the following to head
        preceding = NULL; // Set the preceding to NULL
        head = new_node;  // Set the head to new_node
    }
    else
    {
        set_position(position - 1);  // Set the position to position - 1
        preceding = current;         // Set the preceding to current
        following = preceding->next; // Set the following to the next of preceding
    }

    new_node->next = following; // Set the next of new_node to following
    new_node->back = preceding; // Set the back of new_node to preceding

    if (preceding != NULL)
        preceding->next = new_node; // Set the next of preceding to new_node
    if (following != NULL)
        following->back = new_node; // Set the back of following to new_node

    current = new_node;          // Set the current to new_node
    current_position = position; // Set the current position to position
    count++;                     // Increase the count

    return success;
}

/* Pre: The position is valid, i.e., 0 <= position < count.
   Post: Removes the entry at position, returning it in x.
   All entries beyond position are shifted left. The count is decremented by 1.
*/
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
    if (position < 0 || position >= count) // Invalid position
        return Range_Error;
    Node<List_entry> *previous, *following; // Nodes to be removed
    if (position > 0)
    {
        set_position(position - 1);           // Set the position to position - 1
        previous = current;                   // Set the previous to current
        following = previous->next;           // Set the following to the next of previous
        previous->next = following->next;     // Set the next of previous to the next of following
        if (following->next)                  // Set the back of the next of following to previous
            following->next->back = previous; // Set the back of the next of following to previous
    }
    else
    {
        following = head;      // Set the following to head
        head = head->next;     // Set the head to the next of head
        if (head)              // Set the back of head to NULL
            head->back = NULL; // Set the back of head to NULL
        // should be added
        current_position = 0; // Set the current position to 0
        current = head;       // Set the current to head
    }
    delete following; // Delete the following
    count--;          // Decrease the count
    return success;   // Remove successfully
}

/*
Pre: None.
Post: The List is initialized to be empty.
*/
template <class List_entry>
void update(List_entry &x)
{
    x *= 2; // Multiply x by 2
}

/*
Pre: None.
Post: Print The Element.
*/
template <class List_entry>
void print(List_entry &x)
{
    cout << x << endl; // Output x
}

/*
Pre: None.
Post: The List is initialized to be empty.
*/
template <class List_entry>
List<List_entry>::List()
{ // Default constructor
    count = 0;
    head = NULL; // Set the head to NULL
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

/*
Pre: None.
Post: Return the size of the list.
*/
template <class List_entry>
int List<List_entry>::size() const
{
    return count; // Return the count
}

/*
Pre: None.
Post: Check the list is full or not.
*/
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
Post: Check the list is empty or not.
*/
template <class List_entry>
bool List<List_entry>::empty() const
{
    return count == 0; // Return if the count is 0
}

/*
Pre: None.
Post: Clear the list.
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
Post: Traverse the list.
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

/*
Pre: None.
Post: Deep copies all the elements from the List 'copy' to this List.
*/
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

/*
Pre: None.
Post: The List is destroyed.
*/
template <class List_entry>
List<List_entry>::~List()
{
    List_entry x;
    while (!empty()) // While the list is not empty
        remove(0, x);
}
