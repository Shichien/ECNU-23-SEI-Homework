#include "Queen1.h"
#include <iostream>

using namespace std;

/*
* Pre : The Queens configuration represents a partially.
* Post: Determine whether the problem has been solved.
*/
bool Queens::is_solved() const {
    return(count == board_size);
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
            cout << " " << queen_square[i][j] << " " << flush;
        }
        cout << " " << endl;
    }
    cout << endl << endl;
}

/*
* Pre: A queen occupies the square in the first unoccupied row (row count) and column col.
* Post: The queen is removed from the square at row count and column col;
*/
void Queens::remove(int col) {
    queen_square[--count][col] = false;
}

/*
* Pre: The square in the first unoccupied row (row count) and column col.
* is not guarded by any queen.
* Post: A queen has been inserted into the square at row count and column.
* col; count has been incremented by 1.
*/
void Queens::insert(int col) {
    queen_square[count++][col] = true;
}

/*
* Post: The Queens object is set up as an empty
* configuration on a chessboard with size squares in each row and column.
*/
Queens::Queens(int size) {
    board_size = size;
    count = 0;
    for (int row = 0; row < board_size; row++)
        for (int col = 0; col < board_size; col++)
            queen_square[row][col] = false;
}

/*
* Post: Returns true or false according as the square in the first
* unoccupied row (row count) and column col is not guarded by any queen.
*/
bool Queens::unguarded(int col) const {
    int i;
    bool ok = true; // turns false if we find a queen in column or diagonal
    for (i = 0; ok && i < count; i++)
        ok = !queen_square[i][col]; // Check upper part of column
    for (i = 1; ok && count - i >= 0 && col - i >= 0; i++)
        ok = !queen_square[count - i][col - i]; // Check upper-left diagonal
    for (i = 1; ok && count - i >= 0 && col + i < board_size; i++)
        ok = !queen_square[count - i][col + i]; // Check upper-right diagonal
    return ok;
}