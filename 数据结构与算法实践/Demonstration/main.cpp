//
// Created by Deralive (10235101526) on 2024/3/19.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Demonstration.cpp"

using namespace std;

int main() {

    // Init The Queue
    ClassQueue<char> Queue;

    // Tip The Necessary Information
    OutTheInformation();
    TipTheNextInput();

    /*
    * Pre : The Queue Is Already Initialized.
    * Post: Continuously Reading Input.
    */
    while (1) {
        char Choice;
        cin >> Choice;
        CheckUsersInput(Choice, Queue);
    }

    system("pause");
    return 0;
}