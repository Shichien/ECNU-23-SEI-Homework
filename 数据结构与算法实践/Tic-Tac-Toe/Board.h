//
// Created by Deralive (10235101526) on 2024/05/08.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include"Move.cpp"
#include"MyStack.cpp"

class Board {

public:

    Board(); //constructor

    bool done() const; //game is over
    void print() const; //print the board
    void instructions() const; //print the instructions
    bool better(int value, int old_value) const; //better value

    bool ValidStep(Move try_it) const; //valid step
    void play(Move try_it); //play the move

    int worst_case() const; //worst case
    int evaluate() const; //evaluate the board
    int legal_moves(MyStack<Move>& moves) const; //legal moves
    int the_winner() const;     //winner

private:

    int squares[3][3]; //board
    int moves_done; //moves done

};