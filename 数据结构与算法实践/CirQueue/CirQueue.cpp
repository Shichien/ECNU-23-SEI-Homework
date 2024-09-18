//
// Created by Deralive (10235101526) on 2024/03/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include<iostream>
#include"CirQueue.h"

using namespace std;

/*
* Pre : None.
* Post: Debug : Show The MaxSize, Front Number, Rear Number, Count Number.
*/

// template<class Type>
// void CirQueue<Type>::Debug() {

//     cout << "MaxQueue:" << MaxQueue << endl;
//     cout << "Front:" << Front << endl;
//     cout << "Rear:" << Rear << endl;
//     cout << "Count:" << Count << endl;
//     cout << endl;

// }

/*
* Pre : None.
* Post: Check the queue is empty or not.
*/
template<class Type>
bool CirQueue<Type>::EmptyQueue() {
    return Count == 0;
}

/*
* Pre : The Queue Is Already Initialized.
* Post: Insert An Element Into The Queue.
*/
template<class Type>
State CirQueue<Type>::Append(Type Item) {
    if (Rear >= MaxQueue) {
        cout << "The Queue Is Overqueue." << endl;
        return Overqueue;
    } else {
        Rear = (Rear + 1) % MaxQueue;
        Queue[Rear] = Item;
        Count++;
        // Debug();
        return Successful;
    }
}

/*
* Pre : The Queue Isn't Empty.
* Post: Output The Element With Removing It From The Queue.
*/
template<class Type>
State CirQueue<Type>::Serve() {
    if (EmptyQueue()) {
        cout << "The Queue Is Empty!" << endl;
        return Lessqueue;
    } else {
        Front = (Front + 1) % MaxQueue;
        Count--;
        return Successful;
    }
}

/*
* Pre : At Least One Element In The Queue.
* Post: Output The Element Without Removing It From The Queue.
*/
template<class Type>
State CirQueue<Type>::Retrieve(Type &Item) {
    if (EmptyQueue()) {
        cout << "The Queue Is Empty!" << endl;
        return Lessqueue;
    } else {
        Item = Queue[Front];
        return Successful;
    }
}

/*
* Pre : None.
* Post: The The Size Of The Queue.
*/
template<class Type>
void CirQueue<Type>::TipTheSize() {
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
void CirQueue<Type>::PrintQueue() {
    if (EmptyQueue()) {
        cout << "The Queue Is Empty!" << endl;
    } else {
        int i = Front;
        cout << "The Queue Has These Elements: ";
        for (int j = 0; j < Count; ++j) {
            cout << Queue[i] << " ";
            i = (i + 1) % MaxQueue;
        }
        cout << endl;
    }
}


/*
* Pre : None.
* Post: Initialize The Stack (Constructor Function).
*/
template<class Type>
CirQueue<Type>::CirQueue() {
    Count = Front = 0;
    Rear = MaxQueue - 1;    //
}


/*
* Pre : None.
* Post: Clear All Elements In The Queue.
*/
template<class Type>
void CirQueue<Type>::Clear() {
    Count = Front = 0;
    Rear = MaxQueue - 1;    // Todo 
    cout << "The empty queue with length 0" << endl;
}