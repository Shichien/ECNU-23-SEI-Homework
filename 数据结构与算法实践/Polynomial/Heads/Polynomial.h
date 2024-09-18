//
// Projected By Deralive (10235101526), release on 25/04/2024
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Extended_Queue.cpp"

class Polynomial : private Extended_Queue { // Use private inheritance.
public:
    Polynomial();
    Polynomial(const Polynomial& original);
    void operator=(const Polynomial& original);
    void read();
    void print() const;
    void equals_sum(Polynomial p, Polynomial q);
    void equals_difference(Polynomial p, Polynomial q);
    void mult_term(Polynomial p, Term t);
    int degree() const;
};