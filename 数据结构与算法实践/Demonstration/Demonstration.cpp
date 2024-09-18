//
// Created by Deralive (10235101526) on 2024/03/19.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "CirQueue.cpp"

using namespace std;

/*
* Pre : None.
* Post: Prompt User For Input.
*/
void OutTheInformation() {
    cout << "Hello!" << endl;
    cout << "This program allows the user to enter one command " << endl;
    cout << "(But only one) on each input line. " << endl;
    cout << "For example, if the command s is entered, then " << endl;
    cout << "The program will serve the front of the queue. " << endl;
    cout << "The valid commands are:" << endl;
    cout << "A - Append the next input character to the extended queue " << endl;
    cout << "S - Serve the front of the extended queue " << endl;
    cout << "R - Retrieve and print the front entry. " << endl;
    cout << "# - The current size of the extended queue " << endl;
    cout << "C - Clear the extended queue (same as delete) " << endl;
    cout << "P - Print the extended queue " << endl;
    cout << "H - This help screen " << endl;
    cout << "Q - Quit " << endl;
}

/*
* Pre : The User Has Already Entered A Command Or Number.
* Post: Prompt User For Input.
*/
void TipTheNextInput() {
    cout << "Select command and press <Enter>:";
}


/*
* Pre : The User Has Already Select A Command.
* Post: Prompt User For Input.
*/
void TipInput() {
    cout << "Please input a char:" << endl;
}

/*
* Pre : The User Has Already Entered A Command Or Number.
* Post: Prompt User For Input.
*/
void WrongInputInformation() {
    cout << "Please enter a valid command:" << endl;
    cout << "[a] Append [s] Serve  [r] Retrieve" << endl;
    cout << "[#] Size [c] Clear [p] Print [h] Help page" << endl;
    cout << "[q]uit." << endl;
    TipTheNextInput();
}

/*
* Pre : The User Has Already Entered A Command Or Number.
* Post: Check User's Input.
*/
void CheckUsersInput(char Choice, CirQueue<char> &Queue) {
    switch (Choice) {
        case 'A':
        case 'a':
            TipInput();
            char In;
            cin >> In;
            Queue.Append(In);
            TipTheNextInput();
            break;
        case 's':
        case 'S':
            Queue.Serve();
            TipTheNextInput();
            break;
        case 'R':
        case 'r':
            char Item2;
            Queue.Retrieve(Item2);
            if (!Queue.EmptyQueue()) {
                cout << "The Front Element Is " << char(Item2) << endl;
            }
            TipTheNextInput();
            break;
        case '#':
            Queue.TipTheSize();
            TipTheNextInput();
            break;
        case 'c':
        case 'C':
            Queue.Clear();
            TipTheNextInput();
            break;
        case 'p':
        case 'P':
            Queue.PrintQueue();
            TipTheNextInput();
            break;
        case 'Q':
        case 'q':
            cout << "Queue Demonstration Finished.";
            system("pause");
            exit(0);
            break;
        case 'H':
        case 'h':
            cout << endl;
            OutTheInformation();
            TipTheNextInput();
            break;
        default:
            cout << "Invalid Input! ";
            WrongInputInformation();
            break;
    }
}