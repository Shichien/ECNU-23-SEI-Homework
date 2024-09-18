/*
*  Projected By Deralive (10235101526), release on 15/03/2024
*/

#include<iostream>
#include"MyStack.cpp"

using namespace std;

int main() {

    MyStack<char> stack;
    stack.InitStack();

    cout << "Bracket Matching Program." << endl;
    cout << "Input a string line:" << endl;

    string Input;
    cin >> Input;
    
    int leftCount = 0;
    int rightCount = 0;

    /*
    * Pre : The User Has Already Entered A Command Or Number.
    * Post: Prompt User For Input.
    */
    for (int i = 0; i < Input.size(); i++) {
        if (Input[i] == '(' || Input[i] == '[' || Input[i] == '{') {

            stack.Stackpush(Input[i]);  //  Encountered a left parenthesis, pushed onto the stack
            leftCount++;

        } else if (Input[i] == ')' || Input[i] == ']' || Input[i] == '}') {

            rightCount++;

            /*
            * Pre : There are already some left parentheses in the stack
            * Post: Encounter a right parenthesis,
            * pop the left parenthesis out of the stack,
            * to see if it matches.
            */

            //  If the pop-up fails, it means that there is no matching left and right parentheses on the stack
            char item;
            if (!stack.Stackpop(item)) { 
                cout << "1.Unmatched opening bracket(s) detected." << endl;
                return 0;
            }
            
            //  After popping up, check if the bracket type matches
            if ((item == '(' && Input[i] != ')') || (item == '[' && Input[i] != ']') || (item == '{' && Input[i] != '}')) {
                cout << "1.Unmatched opening bracket(s) detected." << endl;
                return 0;
            }

        }
    }


    if (stack.Empty()) {
        if (leftCount == rightCount) {
            cout << "0. Ok, matched!" << endl;
        } else {
            cout << "2.Unmatched closing bracket ) detected." << endl;
        }
    } else {
        cout << "1.Unmatched opening bracket(s) detected." << endl;
    }

    system("pause");
    return 0;
}
