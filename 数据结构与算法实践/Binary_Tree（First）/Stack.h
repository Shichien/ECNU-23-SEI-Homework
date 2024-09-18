//
// Created by Deralive (10235101526) on 2024/4/11.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

//  Define enumeration variables as return values for subsequent functions
enum State {
    Success,
    Overflow,
    Underflow,
};

template<class T>
class Stack {
public:

    // Constructor Function
    Stack(); 
    
    // Class Methods
    State pop();    //  Pop an element from the stack
    State push(const T& Item);  //  Pushing a newly acquired element onto the stack
    State top(T& Item) const;   //  Output an element at the top of the stack to the user interface, but do not pop that element out of the stack
    Node<T>* GetTop() const;    //  Return the top_node pointer.

    // Additional Methods
    int size();
    bool empty() const; // Check the stack is empty or not, if so, return 1.
    void clear();

    // Deconstructor Function
    ~Stack();

private:

    Node<T>* top_node;
    
};
