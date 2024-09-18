/*
*  Projected By Deralive (10235101526), release on 15/03/2024
*/

#include<iostream>
#include"MyStack.cpp"

using namespace std;

int main() {

    /*
    * Pre : None.
    * Post: Initialize The Stack.
    */
    MyStack<int> stack;
    stack.InitStack();

    /*
    * Pre : None.
    * Post: Prompt User For Input.
    */
    cout << "Please enter the decimal number n to convert:" << endl;
    int num;
    cin >> num;
    cout << "Please enter the decimal number r to convert to:" << endl;
    int r;
    cin >> r;

    /*
    * Pre : The User Has Already Entered Two Numbers.
    * Post: By Using The Round And Round Division Method, Push The Remainder Obtained Each Time Onto The Stack.
    */
    while (num != 0) {
        stack.Stackpush(num % r);
        num = num / r;
    }

    /*
    * Pre : The User Has Already Entered Two Numbers.
    * Post: Continuously Extracting Elements From The Stack To Achieve Reverse Order Output.
    */
    while (!stack.Empty()) {

        int item;
        stack.Stackpop(item);
        if (item < 10) {
            cout << item << " ";
        } else {
            cout << (char) (item + 55) << " ";
        }
    }
    cout << endl;

    system("pause");
    return 0;
}
