//
// Created by Deralive (10235101526) on 2024/4/19.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Queue.cpp"

typedef Term Queue_entry; // Todo: Change the type of Queue_entry to Term.

class Extended_Queue : public Queue {
public:
    int size() const; // Return the number of elements in the queue.
    void clear(); // Clear the queue.
    Queue_Error_code serve_and_retrieve(Queue_entry& item); // Output the element with removing it from the queue.
};