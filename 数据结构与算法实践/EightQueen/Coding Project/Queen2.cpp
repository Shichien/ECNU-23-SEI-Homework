#include "Queen2.h"
#include <iostream>
using namespace std;

/*
* Post: The Queens object is set up as an empty
* configuration on a chessboard with size squares in each row and column.
*/
Queens::Queens(int size) {
    board_size = size;
    count = 0;
    for (int i = 0; i < board_size; i++)col_free[i] = true;
    for (int j = 0; j < (2 * board_size - 1); j++)upward_free[j] = true;
    for (int k = 0; k < (2 * board_size - 1); k++)downward_free[k] = true;
}

/*
* Post: Returns true or false according as the square in the first
* unoccupied row (row count) and column col is not guarded by any queen.
*/
bool Queens::unguarded(int col) const {
    return col_free[col]
        && upward_free[count + col]
        && downward_free[count - col + board_size - 1];
}

/*
* Pre: The square in the first unoccupied row (row count) and column col.
* is not guarded by any queen.
* Post: A queen has been inserted into the square at row count and column.
* col; count has been incremented by 1.
*/
void Queens::insert(int col) {
    queen_in_row[count] = col;
    col_free[col] = false;
    upward_free[count + col] = false;
    downward_free[count - col + board_size - 1] = false;
    count++;
}

/*
* Pre: A queen occupies the square in the first unoccupied row (row count) and column col.
* Post: The queen is removed from the square at row count and column col;
*/
void Queens::remove(int col) {
    count--;
    col_free[col] = true;
    upward_free[count + col] = true;
    downward_free[count - col + board_size - 1] = true;
}

/*
* Pre : The Queens configuration represents a partially completed
* arrangement of non-attacking queens on a chessboard.
* Post: All n-queens solutions that extend the given configuration are printed.
*/
void Queens::print() const {
    int i, j;
    for (i = 0;i < board_size;i++) {
        for (j = 0;j < board_size;j++) {
            if (j == queen_in_row[i]) cout << " " << "1" << " " << flush;
            else cout << " " << "0" << " " << flush;
        }
        cout << " " << endl;
    }
    cout << endl << endl;
}

/*
* Pre : The Queens configuration represents a partially.
* Post: Determine whether the problem has been solved.
*/
bool Queens::is_solved() const {
    return(count == board_size);
}