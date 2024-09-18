//
// Created by Deralive (10235101526) on 2024/04/25.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Term.h"

/*
* Post: The Term is initialized with the given coefficient
* and exponent, or with default parameter values of 0.
*/
Term::Term(int exponent, double scalar) {
    degree = exponent; // Degree of the term, the exponent of x
    coefficient = scalar; // Coefficient of the term, the scalar of x
}