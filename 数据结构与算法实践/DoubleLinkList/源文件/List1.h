//
// Created by Deralive (10235101526) on 2024/05/16.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Node.cpp"

// template <class Node_entry>

// struct Node
// {
// 	// data members
// 	Node_entry entry;
// 	Node<Node_entry> *next;
// 	// constructors
// 	Node();
// 	Node(Node_entry item, Node<Node_entry> *link = NULL);
// };

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
	~List();									  // Destructor
	List();										  // Default constructor
	List(const List<List_entry> &copy);			  // Copy constructor
	void operator=(const List<List_entry> &copy); // Overload the assignment operator
	int size() const;							  // Return the number of entries in the List
	bool full() const;							  // If the List is full, return true; otherwise, return false
	bool empty() const;							  // If the List is empty, return true; otherwise, return false
	void clear();								  // Clear all entries from the List
	void traverse(void (*visit)(List_entry &));	  // Apply the function visit to each entry in the List

	Error_code retrieve(int position, List_entry &x) const; // Retrieve the entry at position in the List
	Error_code replace(int position, const List_entry &x);	// Replace the entry at position in the List with x
	Error_code remove(int position, List_entry &x);			// Remove the entry at position in the List and return it in x
	Error_code insert(int position, const List_entry &x);	// Insert x into the List at position

protected:
	// Data members for the linked list implementation now follow.
	int count;
	Node<List_entry> *head;
	// The following auxiliary function is used to locate list positions
	Node<List_entry> *set_position(int position) const;
	// The following auxiliary function is used to delete all the nodes in the list
};