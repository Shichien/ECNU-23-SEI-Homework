//
// Created by Deralive (10235101526) on 2024/05/08.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include"Board.cpp"
#include<iostream>
using namespace std;

int main() {

    Board game; //create a game
    /*
    *问题2：如何改写成电脑对电脑的程序？
    *创建两个Board对象，每个对象代表一个电脑玩家。
    *在游戏循环中，两个对象轮流调用play和look_ahead函数
    *以模拟电脑对电脑的游戏。
    */

    Move recommended; //recommended move
    int x, y;
    int i = 9;
    game.instructions();

    while (!game.done()) { //game is not over

        look_ahead(game, i, recommended);  //look ahead
        game.play(recommended); //play the recommended move
        cout << "Computer:" << endl;
        game.print();

        /*
        问题3：如何改写成人先走的程序？
        在游戏开始时，用户输入，然后再让电脑进行移动
        （通过调用play函数来实现）
        */
        if (game.done()) break;
        cout << "Your turn:" << endl;
        cout << "X:"; //your turn
        cin >> x;
        cout << "Y:"; //your turn
        cin >> y;
        Move me(x, y); //your move

        game.play(me); //play your move
        game.print(); //print the board
        i--;
    }

    if (game.the_winner() == 1) // 1 is computer
        cout << "Game over with computer win." << endl;
    else if (game.the_winner() == 2)  // 2 is you
        cout << "Game over with you win." << endl; //impossible
    else
        cout << "Game over with a draw." << endl; //only when you go (1,1) at first step.

    system("pause");
    return 0;

}