//
// Projected By Deralive (10235101526), release on 25/04/2024
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Polynomial.h"
#include <iostream>

using namespace std;

/*
* Pre : None.
* Post: Initialize The Polynomial (Constructor Function).
*/
Polynomial::Polynomial() {
    front = NULL;
    rear = NULL;
}

/*
* Pre : The Polynomial Isn't Empty.
* Post: Clear The Polynomial.
*/
Polynomial::Polynomial(const Polynomial& original) {
    SmallNode* new_front, * new_copy, * original_front = original.front, * new_rear;
    if (original_front == NULL) {
        new_front = NULL;
        new_rear = NULL;
    }
    else { // Duplicate the linked nodes
        new_copy = new_front = new SmallNode(original_front->entry);
        while (original_front->next != 0) {
            original_front = original_front->next;
            new_copy->next = new SmallNode(original_front->entry);
            new_copy = new_copy->next;
        }
        new_rear = new_copy;
    }
    front = new_front;
    rear = new_rear;
}

/*
* Pre : The Polynomial Isn't Empty.
* Post: Clear The Polynomial.
*/
void Polynomial::operator =(const Polynomial& original) {
    SmallNode* new_front, * new_copy, * original_front = original.front, * new_rear;
    if (original_front == NULL) {
        new_front = NULL;
        new_rear = NULL;
    }
    else { // Duplicate the linked nodes
        new_copy = new_front = new SmallNode(original_front->entry);
        while (original_front->next != 0) {
            original_front = original_front->next; // Advance the original list
            new_copy->next = new SmallNode(original_front->entry); // Create a new node
            new_copy = new_copy->next; // Advance the new list
        }
        new_rear = new_copy;
    }
    while (!empty()) // Clean out old Queue entries
        serve();
    front = new_front;
    rear = new_rear;
}

/*
* Pre : The Polynomial Isn't Empty.
* Post: The Polynomial is printed to cout.
*/
void Polynomial::print() const

{
    SmallNode* print_node = front;
    bool first_term = true;
    while (print_node != NULL) {
        Term& print_term = print_node->entry;
        if (first_term) { // In this case, suppress printing an initial '+'.
            first_term = false;
            if (print_term.coefficient < 0) cout << "- ";
        }
        else if (print_term.coefficient < 0) cout << " - ";
        else cout << " + ";
        double r = (print_term.coefficient >= 0) ? print_term.coefficient : -(print_term.coefficient);
        if (r != 1) cout << r;
        if (print_term.degree > 1) cout << " X^" << print_term.degree;
        if (print_term.degree == 1) cout << " X";
        if (r == 1 && print_term.degree == 0) cout << " 1";
        print_node = print_node->next;
    }
    if (first_term)
        cout << "0"; // Print 0 for an empty Polynomial.
    cout << endl;
}

/*
* Pre : None.
* Post: Read The Polynomial From the stack.
*/
void Polynomial::read() {
    clear();
    double coefficient;
    int last_exponent, exponent;
    bool first_term = true;
    cout << "Enter the coefficients and exponents for the polynomial,one pair per line." << endl
        << "Exponents ( >=0 ) must be in descending order." << endl
        << "Enter a coefficient of 0 or an exponent of 0 to terminate." << endl;
    do {
        cout << "coefficient? " << flush;
        cin >> coefficient;
        if (coefficient != 0.0) {
            cout << "exponent? " << flush;
            cin >> exponent;
            if ((!first_term && exponent >= last_exponent) || exponent < 0) {
                exponent = 0;
                cout << "Bad exponent: Polynomial terminates without its last term."
                    << endl;
            }
            else {
                Term new_term(exponent, coefficient);
                append(new_term);
                first_term = false;
            }
            last_exponent = exponent;
        }
        else {
            cout << "The following Polynomial has been entered the stack:" << endl;
            print(); // Show the polynomial
        }
    } while (coefficient != 0.0 && exponent != 0);
}

/*
* Post: If the Polynomial is identically 0, a result of -1 is
* returned.
* Otherwise the degree of the Polynomial is returned.
*/
int Polynomial::degree() const {
    if (empty()) return -1;
    Term lead;
    retrieve(lead);
    return lead.degree;
}

/*
* Pre : None.
* Post: Add the Polynomial p to the Polynomial q.
*/
void Polynomial::equals_sum(Polynomial p, Polynomial q) {
    clear();
    while (!p.empty() || !q.empty()) { // Add corresponding terms
        Term p_term, q_term;
        if (p.degree() > q.degree()) { // Add p's term
            p.serve_and_retrieve(p_term); // Serve the term
            append(p_term); // Append the term
        }
        else if (q.degree() > p.degree()) {
            q.serve_and_retrieve(q_term);
            append(q_term);
        }
        else {
            p.serve_and_retrieve(p_term); // Serve the term
            q.serve_and_retrieve(q_term); // Serve the term
            if (p_term.coefficient + q_term.coefficient != 0) {
                Term answer_term(p_term.degree, p_term.coefficient + q_term.coefficient);
                append(answer_term);
            }
        }
    }
}

/*
* Pre : None.
* Post: Subtract the Polynomial q from the Polynomial p.
*/
void Polynomial::equals_difference(Polynomial p, Polynomial q) {
    // 基本思路与上方equals_sum 相同，只是在相减时，需要将 q 的系数取负
    clear();
    while (!p.empty() || !q.empty()) {
        Term p_term, q_term;
        if (p.degree() > q.degree()) {
            p.serve_and_retrieve(p_term);
            append(p_term);
        }
        else if (q.degree() > p.degree()) {
            q.serve_and_retrieve(q_term);
            Term answer_term(q_term.degree, -q_term.coefficient);
            append(answer_term);
        }
        else {
            p.serve_and_retrieve(p_term);
            q.serve_and_retrieve(q_term);
            if (p_term.coefficient - q_term.coefficient != 0) {
                Term answer_term(p_term.degree, p_term.coefficient - q_term.coefficient);
                append(answer_term);
            }
        }
    }

}

/*
* Pre : None.
* Post: Multiply the Polynomial p by the Polynomial q.
*/
void Polynomial::mult_term(Polynomial p, Term t) {
    // 基本思路与上方 equals_sum 相同，只是在相乘时，需要将 p 的每一项与 t 相乘
    Polynomial answer;
    while (!p.empty()) {
        Term p_term;
        p.serve_and_retrieve(p_term);
        Term answer_term(p_term.degree + t.degree, p_term.coefficient * t.coefficient);
        answer.append(answer_term);
    }
    *this = answer;
}