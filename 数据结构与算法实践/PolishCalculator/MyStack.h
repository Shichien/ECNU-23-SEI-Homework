#include <iostream>
#include <string>
using namespace std;

#define Maxsize 10

enum State {
    Lessstack,
    SuccessOperate,
    Overstack,
};

template <class T>
class MyStack {
public:
    MyStack(); // 构造函数
    void InitStack(); // 初始化栈
    bool Empty() const; // 判断栈是否为空
    State Stackpop(T &Out); // 出栈操作
    State Stackpush(const T &Item); // 入栈操作
    State StackTop(T &Top);
    
private:
    int cnt;
    T Stack[Maxsize];
};

/*
* Pre : None.
* Post: Initialize The Stack.
*/
template <class T>
MyStack<T>::MyStack() {
    cnt = 0;
}

template <class T>
void MyStack<T>::InitStack() {
    cnt = 0;
}

/*
* Pre : The Stack Is Already Initialized.
* Post: Chech The Stack Is Empty Or Not.
*/
template <class T>
bool MyStack<T>::Empty() const {
    return (cnt == 0);
}

/*
* Pre : The Stack Is Already Initialized.
* Post: Output The Top Item In The Stack To User.
*/
template <class T>
State MyStack<T>::StackTop(T &Top){
    if (cnt <= 0) {
        cout << "The Stack Is Empty!" << endl;
        return Lessstack;
    } else {
        Top = Stack[cnt - 1];
        return SuccessOperate;
    }
}

/*
* Pre : The Stack Is Already Initialized, And At Lease One Item.
* Post: Pop The Top Item In The Stack.
*/
template <class T>
State MyStack<T>::Stackpop(T &Out) {
    if (cnt <= 0) {
        cout << "The Stack Is Empty!" << endl;
        return Lessstack;
    } else {
        Out = Stack[--cnt];
        return SuccessOperate;
    }
}

/*
* Pre : The Stack Is Already Initialized, Less Than Stack's Maxsize.
* Post: Push The Item Into The Stack.
*/
template <class T>
State MyStack<T>::Stackpush(const T &Item) {
    if (cnt >= Maxsize) {
        cout << "The Stack Is Over The MaxSize" << endl;
        return Overstack;
    } else {
        Stack[cnt++] = Item;
        return SuccessOperate;
    }
}
