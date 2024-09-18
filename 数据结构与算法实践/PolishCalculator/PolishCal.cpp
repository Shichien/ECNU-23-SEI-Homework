#include <iostream>
#include "MyStack.h"
using namespace std;

MyStack<double> stack;

//  Define The Functions At Head, In Order To Read Easily.
void OutTheInformation();
void Add();
void Min();
void Mul();
void Div();
void CheckUsersInput(char Choice);

//  You Can See The Process Of The exe.
int main() {
    stack.InitStack();
    OutTheInformation();
    char Choice;
    double Input;
    while (cin >> Choice) {
        CheckUsersInput(Choice);
    }
}

/*
* Pre : None.
* Post: Prompt User For Input.
*/
void OutTheInformation() {
    cout << "This is a reverse Polish Calculator." << endl;
    cout << "Please enter a valid command:" << endl;
    cout << "[?] push to stack   [=] print top" << endl;
    cout << "[+] [-] [*] [/] are arithmetic operations" << endl;
    cout << "[Q]uit." << endl;
    cout << "Select command and press <Enter>:";
}

/*
* Pre : The User Has Already Entered A Command Or Number.
* Post: Prompt User For Input.
*/
void TipTheNextInput(){
    cout << "Select command and press <Enter>:";
}

/*
* Pre : The Stack Contains 2 Numbers At Least.
* Post: Add Two Numbers Together.
*/
void Add() {
    double a, b;
    if (stack.Stackpop(b) == SuccessOperate && stack.Stackpop(a) == SuccessOperate) {
        stack.Stackpush(a + b);
    }
    TipTheNextInput();
}

/*
* Pre : The Stack Contains 2 Numbers At Least.
* Post: Subtracting Two Numbers.
*/
void Min() {
    double a, b;
    if (stack.Stackpop(b) == SuccessOperate && stack.Stackpop(a) == SuccessOperate) {
        stack.Stackpush(a - b);
    }
    TipTheNextInput();
}

/*
* Pre : The Stack Contains 2 Numbers At Least.
* Post: Multiplying Two Numbers.
*/
void Mul() {
    double a, b;
    if (stack.Stackpop(b) == SuccessOperate && stack.Stackpop(a) == SuccessOperate) {
        stack.Stackpush(a * b);
    }
    TipTheNextInput();
}

/*
* Pre : The Stack Contains 2 Numbers At Least.
* Post: Dividing Two Numbers.
*/
void Div() {
    double a, b;
    if (stack.Stackpop(b) == SuccessOperate && stack.Stackpop(a) == SuccessOperate) {
        if (b != 0) {
            stack.Stackpush(a / b);
        } else {
            cout << "Error: Division by zero!" << endl;
            stack.Stackpush(a);
            stack.Stackpush(b);
        }
    }
    TipTheNextInput();
}

/*
* Pre : The User Has Already Entered A Command Or Number.
* Post: Check User's Input.
*/
void CheckUsersInput(char Choice) {
    switch (Choice) {
        case '?':
            cout << "Enter a Real Number: ";
            double Input;
            cin >> Input;
            stack.Stackpush(Input);
            TipTheNextInput();
            break;
        case '+':
            Add();
            break;
        case '-':
            Min(); 
            break;
        case '*':
            Mul();
            break;
        case '/':
            Div();
            break;
        case 'Q':
        case 'q':
            cout << "Calculation Finished." << endl;
            system("pause");
            exit(0);
            break;
        case '=':
            if (!stack.Empty()) {
                double result;
                stack.StackTop(result);
                cout << result << endl;
            } else {
                cout << "Stack is empty!" << endl;
            }
            TipTheNextInput();
            break;
        default:
            cout << "Invalid Input! Please Input Another Number or Command: ";
            break;
    }
}
