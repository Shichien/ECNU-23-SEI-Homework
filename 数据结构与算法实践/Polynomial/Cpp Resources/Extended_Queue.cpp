//
// Created by Deralive (10235101526) on 2024/4/19.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include"Extended_Queue.h"

/*
* Pre : None.
* Post: Clear all elements in the queue.
*/
void Extended_Queue::clear() {
    while (!Queue::empty()) {
        Queue::serve();
    }
    // cout << "The queue has initialized." << endl;
}

/*
* Pre : None.
* Post: Return the size of the queue.
*/
int Extended_Queue::size() const {
    int count = 0;
    SmallNode* tempptr = Queue::front;
    while (tempptr != nullptr) {
        count++;
        tempptr = tempptr->next;
    }
    return count;
}

/*
* Pre : The Extended_Queue is initialized.
* Post: Serve and retrieve the element in the queue.
*/
Queue_Error_code Extended_Queue::serve_and_retrieve(Queue_entry& item) {
    if (Queue::empty()) {
        return underflow;
    }
    else {
        Queue::retrieve(item);
        Queue::serve();
        return success;
    }
}

/*
* Pre : Some Elements In The Queue.
* Post: Print All Elements In The Queue.
*/
//
// void Extended_Queue::print() {
//     if (empty()) {
//         cout << "The Queue Is Empty!" << endl;
//     }
//     else {
//         cout << "The Queue Contains: ";
//         for (int i = front; i < rear; i++) {
//             cout << QueueWare[i] << " ";
//         }
//         cout << endl;
//     }
// }