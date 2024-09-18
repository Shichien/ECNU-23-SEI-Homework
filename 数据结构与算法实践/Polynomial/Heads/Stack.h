//
// Projected By Deralive (10235101526), release on 08/03/2024
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Node.cpp"

// Define the type of data stored in the stack
enum Error_code {
    Success,
    Overflow,
    Underflow,
};

class Stack {
public:
    // Standard Stack methods
    Stack(); // Constructor
    ~Stack(); // Safety features for linked structures

    bool empty() const; // Determine whether the stack is empty

    Error_code push(const Node_entry& item); // Add an item to the stack
    Error_code pop(); // Remove the top item from the stack
    Error_code top(Node_entry& item) const; // Retrieve the top item from the stack

protected:
    Node* top_node; // Pointer to the top of the stack
};