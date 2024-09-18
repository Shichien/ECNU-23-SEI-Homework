//
// Created by Deralive (10235101526) on 2024/03/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include<iostream>
#include"CirQueue.cpp"

using namespace std;

int main(){
    
    // Init The Cir Queue.
    CirQueue<int> Queue;

    // Tip The Information.
    cout << " Type in an integer n followed by n decimal numbers. " << endl
    << " The numbers will be printed in original order." << endl;

    int cnt;
    cin >> cnt;

    // Get The Input From User's
    for (int i = 0; i < cnt ; i++){
        int input;
        cin >> input;
        Queue.Append(input);
    }
        // Print The Elements In The Queue.
        Queue.PrintQueue();

    system("pause");
    return 0;

}