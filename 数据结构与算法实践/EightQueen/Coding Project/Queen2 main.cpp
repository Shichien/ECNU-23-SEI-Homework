#include"time.h"
#include"Queen1.cpp"
#include<iostream>

using namespace std;

int g_count = 0;    // The count of the answer.

/*
* Pre : None.
* Post: Print the information of the game.
*/
void print_information() {
    cout << "This is the Queens game." << endl;
}

/*
* Pre : The Queens configuration represents a partially completed
* arrangement of non-attacking queens on a chessboard.
* Post: All n-queens solutions that extend the given configuration are printed.
* The configuration is restored to its initial state.
* Uses: The class Queens and the function solve_from, recursively.
*/
void solve_from(Queens& configuration) {
    if (configuration.is_solved()) {
        g_count++;
        // configuration.print();
    }
    else {
        for (int col = 0; col < configuration.board_size; col++) {
            if (configuration.unguarded(col)) {
                configuration.insert(col);
                solve_from(configuration); // Recursively continue to add queens.
                configuration.remove(col);
            }
        }
    }
}


/*
* Pre : The user enters a valid board size.
* Post: All solutions to the n-queens puzzle for the selected board size are printed.
* Uses: The class Queens and the recursive function solve_from.
*/
// int main()

// {
//     cout << "This is Eight-Queen Question (Version 1)" << endl;
//     int board_size;
//     void solve_from(Queens & configuration);
//     void print_information();
//     print_information();
//     cout << "What is the size of the board? " << flush;
//     cin >> board_size;
//     if (board_size < 0 || board_size > max_board)
//         cout << "The number must be between 0 and " << max_board << endl;
//     else {
//         Queens configuration(board_size); // Initialize empty configuration.
//         solve_from(configuration); // Find all solutions extending configuration.
//     }
// }

int main() {
    cout << "This is Eight-Queen Question (Version 2)" << endl;
    cout << "Projected By: Deralive 10235101526" << endl;

    int board_size;
    cout << "What is the size of the board? " << flush;
    cin >> board_size;

    double start = time(NULL); // Record the start time, use time.h to calculate the time.

    if (board_size < 0 || board_size > max_board) {
        cout << "The number must be between 0 and " << max_board << endl;
    }
    else {
        Queens configuration(board_size); // Initialize empty configuration.
        solve_from(configuration); // Find all solutions extending configuration.
    }
    double end = time(NULL);
    cout << "It takes time: " << (end - start) << "(s)" << endl;
    cout << "The count of the answer is: " << g_count << endl;
    system("pause");
    return 0;
}