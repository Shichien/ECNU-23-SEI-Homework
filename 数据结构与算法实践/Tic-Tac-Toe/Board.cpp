//
// Created by Deralive (10235101526) on 2024/05/08.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Board.h"
#include<iostream>
using namespace std;

/*
* Pre : None
* Post: TheBoard is initialized as empty.
*/
Board::Board() {
    for (int i = 0; i < 3; i++) // Initialize the board
        for (int j = 0; j < 3; j++)
            squares[i][j] = 0;
    moves_done = 0; // Initialize the number of moves
}

/*
* Pre : None
* Post: The instructions for the game are printed.
*/
void Board::instructions() const {
    cout << "This is a Tic-Tac-Toe game. Wait for computer going..." << endl; //print the instructions
}

/*
* Pre : None
* Post: The board is printed to the screen.
*/
void Board::print() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << " " << squares[i][j]; //print the board
        cout << " " << endl;
    }
    cout << endl;
}

/*
问题 4 ：
如何检测人走棋合法性？
使用ValidStep函数来检测用户的移动是否合法
这个函数接收一个Move对象作为参数
如果这个移动是合法的，它就返回true，否则返回false
在用户输入移动后，调用这个函数来检查移动是否合法
如果移动不合法，程序会提示用户重新输入
*/

/*
* Pre : The Move try_it Is Already Initialized.
* Post: Check The Move try_it Is Valid Or Not.
*/
bool Board::ValidStep(Move try_it) const {
    if (squares[try_it.row][try_it.col] == 0) //check if the move is valid
        return true;
    else
        return false;
}

/*
* Pre : The Move try_it Is Already Initialized.
* Post: Play The Move try_it On The Board.
*/
void Board::play(Move try_it) {
    squares[try_it.row][try_it.col] = moves_done % 2 + 1; //play the move
    moves_done++; //increment the number of moves
}

/*
* Post: Return either a value of 0 for a position where neither player has won, a value
* of 1 if the first player has won, or a value of 2 if the second player has won.
*/
int Board::the_winner() const {
    int i;
    for (i = 0; i < 3; i++)
        if (squares[i][0] && squares[i][0] == squares[i][1] && squares[i][0] == squares[i][2]) // check the winner
            return squares[i][0];
    for (i = 0; i < 3; i++)
        if (squares[0][i] && squares[0][i] == squares[1][i] && squares[0][i] == squares[2][i]) // check the winner
            return squares[0][i];
    if (squares[0][0] && squares[0][0] == squares[1][1] && squares[0][0] == squares[2][2]) // check the winner
        return squares[0][0]; // check the winner
    if (squares[0][2] && squares[0][2] == squares[1][1] && squares[2][0] == squares[0][2]) // check the winner
        return squares[0][2];
    return 0;
}

/* Post: Return true if the game is over;
* either because a player has already won or
* because all nine squares have been filled.
*/
bool Board::done() const {
    return moves_done == 9 || the_winner() > 0;
}

/*
* Post: Return the number of legal moves for the current player.
*/
int Board::legal_moves(MyStack<Move>& moves) const {
    int count = 0;
    while (!moves.empty()) moves.pop(); //clear the stack
    for (int i = 0; i < 3; i++) //find the legal moves
        for (int j = 0; j < 3; j++)
            if (squares[i][j] == 0) {
                Move can_play(i, j); //legal move
                moves.push(can_play); //push the move into the stack
                count++; //increment the number of legal moves
            }
    return count;
}

/*
* Post: Return either a value of 0 for a position where neither player has won, a
* positive value between 1 and 9 if the first player has won, or a negative value
* between - 1 and - 9 if the second player has won,
*/
int Board::evaluate() const {
    int winner = the_winner(); //check the winner
    if (winner == 1) return 10 - moves_done; //for first player 1
    else if (winner == 2) return moves_done - 10; //for second player 2
    else return 0; //no winner yet
}

/*
* Pre: The Value And Old_Value Are Already Initialized.
* Post: Return True If The Value Is Better Than The Old_Value.
*/
bool Board::better(int value, int old_value) const {

    if (moves_done % 2) return value < old_value; // for second player 2
    else return value > old_value; // for first player 1
}

/*
* Pre : None.
* Post: Return either a value of 10 if the first player has won, or a value of -10 if the second player has won.
*/
int Board::worst_case() const {
    if (moves_done % 2)return 10; //for second player 2
    else return -10; //for first player 1
}

/*
* Pre : The Board Is Already Initialized.
* Post: Look Ahead The Game And Return The Best Value.
*/
int look_ahead(const Board& game, int depth, Move& recommended) {
    /*
    问题1：如何使电脑智能降低？
    减少look_ahead函数中depth参数的值，它决定了电脑预测未来的步数。
    如果减少这个值，电脑的预测能力就会降低，从而降低其智能。
    */
    if (game.done() || depth == 0) // base case
        return game.evaluate(); // return the value of the board
    else {
        MyStack<Move> moves; // stack of possible moves
        game.legal_moves(moves); // find the legal moves
        int value, best_value = game.worst_case(); // initialize the best value
        while (!moves.empty()) { // loop through the possible moves
            Move try_it, reply; // move to try and reply
            moves.top(try_it); // get the next move
            Board new_game = game; // copy the current game
            new_game.play(try_it); // play the move
            value = look_ahead(new_game, depth - 1, reply); // recursive call
            if (game.better(value, best_value)) {
                // try_it is the best move yet found
                best_value = value; // update the best value
                recommended = try_it; // update the recommended move
            }
            moves.pop(); // remove the move from the stack
        }
        return best_value; // return the best value
    }
}
