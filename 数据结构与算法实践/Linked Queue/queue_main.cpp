//
// Created by Deralive (10235101526) on 2024/4/18.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include <fstream>
#include "Extended_Queue.cpp"

int main() {

    /*
    * Pre : None.
    * Post: Create a new queue, prompt the user for input, and read the input.
    */
    Queue<char> que1, que2;
    Extended_Queue<char> extque1;
    int n;
    char item;
    cout << "please input a integer n followed by n chars" << endl;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> item;
        que1.append(item);
    }

    /*
    * Pre : None.
    * Post: Tests whether the overloaded operator ran successfully
    */
    que2 = que1;

    /*
    * Pre : Queue 1 has been initialized
    * Post: Using the Retrieve method and serve method.
    */
    cout << endl << "Print Que1:" << endl;
    while (!que1.empty()) {
        que1.retrieve(item);
        cout << item << " ";
        que1.serve();
    }

    cout << endl << "Print Que2:" << endl;

    while (!que2.empty()) {
        que2.retrieve(item);
        cout << item << " ";
        que2.serve();
    }


    cout << endl << "please input another integer n followed by n chars:" << endl;

    /*
    * Pre : None.
    * Post: Testing the Extended queue is work out or not.
    */
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> item;
        extque1.append(item);
    }

    cout << endl << "extque1_size = " << extque1.size() << endl;
    cout << endl << "Print extque1 : " << endl;
    while (!extque1.empty()) {
        extque1.serve_and_retrieve(item);
        cout << item << " ";
    }
    cout << endl;
    system("pause");
}


