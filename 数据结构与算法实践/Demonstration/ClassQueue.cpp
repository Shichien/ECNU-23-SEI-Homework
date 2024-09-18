//
// Created by Deralive (10235101526) on 2024/3/19.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include<iostream>
#include"ClassQueue.h"

using namespace std;

/*
* Pre : None.
* Post: Check the queue is empty or not.
*/
template<class Type>
bool ClassQueue<Type>::EmptyQueue() {
    return Count == 0;
}

/*
* Pre : The Queue Is Already Initialized.
* Post: Insert An Element Into The Queue.
*/
template<class Type>
State ClassQueue<Type>::Append(Type Item) {
    if (Rear >= MaxQueue) {
        cout << "The Queue Is Overqueue." << endl;
        return Overqueue;
    } else {
        Queue[Rear++] = Item;
        Count++;
        cout << "Operation Success! Now The Queue Size Is:" << Count << endl;
        return Successful;
    }
}

/*
* Pre : The Queue Isn't Empty.
* Post: Output The Element With Removing It From The Queue.
*/
template<class Type>
State ClassQueue<Type>::Serve() {
    if (EmptyQueue()) {
        cout << "The Queue Is Empty!" << endl;
        return Lessqueue;
    } else {
        Front++;
        Count--;
        cout << "Operation Success! Now The Queue Size Is:" << Count << endl;
        return Successful;
    }
}

/*
* Pre : At Least One Element In The Queue.
* Post: Output The Element Without Removing It From The Queue.
*/
template<class Type>
State ClassQueue<Type>::Retrieve(Type &Item) {
    if (EmptyQueue()) {
        cout << "The Queue Is Empty!" << endl;
        return Lessqueue;
    } else {
        Item = Queue[Front];
        cout << "Operation Success! Now The Queue Size Is:" << Count << endl;
        return Successful;
    }
}

/*
* Pre : None.
* Post: The The Size Of The Queue.
*/
template<class Type>
void ClassQueue<Type>::TipTheSize() {
    if (EmptyQueue()) {
        cout << "The Queue Is Empty!" << endl;
    } else {
        cout << "The Queue Size Is " << Count << "." << endl;
    }
}

/*
* Pre : Some Elements In The Queue.
* Post: Print All Elements In The Queue.
*/
template<class Type>
void ClassQueue<Type>::PrintQueue() {
    if (EmptyQueue()) {
        cout << "The Queue Is Empty!" << endl;
    } else {
        cout << "The Queue Contains: ";
        for (int i = Front; i < Rear; i++) {
            cout << char(Queue[i]) << " ";
        }
        cout << endl;
    }
}

/*
* Pre : None.
* Post: Initialize The Stack (Constructor Function).
*/
template<class Type>
ClassQueue<Type>::ClassQueue() {
    Count = Rear = Front = 0;
}


/*
* Pre : None.
* Post: Clear All Elements In The Queue.
*/
template<class Type>
void ClassQueue<Type>::Clear() {
    Count = Front = Rear = 0;
    cout << "The empty queue with length 0" << endl;
}