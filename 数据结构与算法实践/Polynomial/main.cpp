//
// Created by Deralive (10235101526) on 2024/04/25.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "Stack.cpp"
using namespace std;

/*
* Post: The program has executed simple polynomial arithmetic
* commands entered by the user.
* Uses: The classes Stack and Polynomial and the functions
* introduction, instructions, do_command, and get_command.
*/
int main() {
    Stack stored_polynomials;
    void introduction();
    void instructions();
    bool do_command(char command, Stack & stored_polynomials);
    char get_command();
    char tolower(char command);
    introduction();
    instructions();
    while (do_command(get_command(), stored_polynomials));
}

/*
* Post: Tip the information about the program to the user.
*/
void introduction() {
    cout << "This is a polynomials program." << endl;
    cout << "(By Deralive 10235101526)" << endl;
}

void instructions() {
    cout << "Please enter a valid command:" << endl
        << "[?] Read a Polynomial" << endl
        << "[=] Return Top Polynomial" << endl
        << "[-] Difference two Polynomial" << endl
        << "[*] Multiply one Polynomial with a Term" << endl
        << "[+] Sum two Polynomial" << endl
        << "[q] Quit." << endl;
}

/*
* Pre: The first parameter specifies a valid calculator command.
* Post: The command specified by the first parameter
* has been applied to the Stack of Polynomial
* objects given by the second parameter.
* A result of true is returned unless command == 'q'.
* Uses: The classes Stack and Polynomial.
*/
bool do_command(char command, Stack& stored_polynomials) {
    Polynomial p, q, r;

    switch (command) {

    case '?':
        p.read();
        if (stored_polynomials.push(p) == overflow)
            cout << "Warning: Stack full, lost polynomial" << endl;
        break;
    case '=':
        if (stored_polynomials.empty())
            cout << "Stack empty" << endl;
        else {
            stored_polynomials.top(p);
            p.print();
        }
        break;

    case '+':
        // Add the top two polynomials on the stack
        if (stored_polynomials.empty())
            cout << "Stack empty" << endl;
        else {
            // Pop the top two polynomials
            stored_polynomials.top(p);
            stored_polynomials.pop();
            if (stored_polynomials.empty()) {
                cout << "Stack has just one polynomial" << endl;
                stored_polynomials.push(p); // Put p back on the stack
            }
            else {
                stored_polynomials.top(q); // Get the next polynomial
                stored_polynomials.pop(); // Remove it from the stack
                r.equals_sum(q, p); // Add the two polynomials
                r.print(); // Print the result
                if (stored_polynomials.push(r) == overflow) // Put the result back on the stack
                    cout << "Warning: Stack full, lost polynomial" << endl;
            }
        }
        break;

    case '-':
        if (stored_polynomials.empty()) // Subtract the top polynomial from the next polynomial
            cout << "Stack empty" << endl;
        else {
            stored_polynomials.top(p); // Get the top polynomial
            stored_polynomials.pop(); // Remove it from the stack 
            if (stored_polynomials.empty()) {
                cout << "Stack has just one polynomial" << endl; // Put p back on the stack
                stored_polynomials.push(p);
            }
            else {
                stored_polynomials.top(q); // Get the next polynomial
                stored_polynomials.pop(); // Remove it from the stack
                r.equals_difference(q, p); // Subtract the two polynomials
                r.print();  // Print the result
                if (stored_polynomials.push(r) == overflow)     // Put the result back on the stack
                    cout << "Warning: Stack full, lost polynomial" << endl;
            }
        }
        break;

    case '*':
        // check if the stack is empty
        if (stored_polynomials.empty()) {
            cout << "Stack empty" << endl;
        }
        else {
            // Multiply the top polynomial by a term
            stored_polynomials.top(q);
            stored_polynomials.pop();

            // Show the information to the user
            cout << "Enter the coefficients and exponents for the term, one pair per line." << endl;
            cout << "Exponents must be >=0." << endl;

            // Get the coefficient and exponent from the user
            double coefficient_value;
            cout << "coefficient? ";
            cin >> coefficient_value;

            int exponent_value;
            cout << "exponent? ";
            cin >> exponent_value;

            Term t;
            t.coefficient = coefficient_value;
            t.degree = exponent_value;

            // Multiply the polynomial by the term
            r.mult_term(q, t);
            cout << "The following Polynomial has been entered the stack:";
            r.print();

            if (stored_polynomials.push(r) == overflow) {
                cout << "Warning: Stack full, lost polynomial" << endl;
            }
        }
        break;

    case 'q':
        cout << "Calculation finished." << endl; // Quit the program
        return false;
    }
    return true;
}

char get_command() {
    // Get the command from the user
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";
    while (waiting) {
        cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' ||
            command == '+' || command == 'q' ||
            command == '*' || command == '-') waiting = false;
        else {
            cout << "Please enter a valid command:" << endl
                << "[?] Read a Polynomial" << endl
                << "[=] Return Top Polynomial" << endl
                << "[+] Sum two Polynomial" << endl
                << "[-] Difference two Polynomial" << endl
                << "[*] Multiply one Polynomial with a Term" << endl
                << "[q] Quit." << endl;
        }
    }
    return command;
}