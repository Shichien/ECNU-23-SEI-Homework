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
template<class T>
void Extended_Queue<T>::clear() {
    while (!Queue<T>::empty()) {
        Queue<T>::serve();
    }
    // cout << "The queue has initialized." << endl;
}

/*
* Pre : None.
* Post: Return the size of the queue.
*/
template<class T>
int Extended_Queue<T>::size() const {
    int count = 0;
    Node<T>* tempptr = Queue<T>::front;
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
template<class T>
State Extended_Queue<T>::serve_and_retrieve(T& item) {
    if (Queue<T>::empty()) {
        return Underflow;
    }
    else {
        Queue<T>::retrieve(item);
        Queue<T>::serve();
        return Success;
    }
}

/*
* Pre : Some Elements In The Queue.
* Post: Print All Elements In The Queue.
*/
// template<class T>
// void Extended_Queue<T>::print() {
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