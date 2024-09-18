/* 
Project By Deralive (张梓卫 10235101526)
Date: 01/03/2024
*/

#include<iostream>
using namespace std;

//传入当前迭代情况，并画出当前图像
void DrawInitGame(int Arr[][62]){
    cout << "\nThe current Life configuration is:";
    for (int i=0; i<20; i++){
        for (int j=0; j<62; j++){
            if (i != 0 && i != 19 && j != 0 && j != 61){
                //抹除边界
                if (Arr[i][j] == 1){
                cout << "*";
                } else {
                cout << "-";
                }
            }
        }
        cout << endl;
    }
}

//查找附近的邻居个数并更改细胞状态
void Search(int Arr[][62]){
    int NewArr[20][62] = {0};  //Arr State Save
    for (int i=1; i<18; i++){
        for (int j=1; j<60; j++){
            int LiveNeibour = 0;
            for (int k = i - 1; k <= i + 1; k++){
                for (int l = j - 1; l <= j + 1; l++){
                    if ((k != i || l != j) && Arr[k][l] == 1){
                        LiveNeibour++;
                        //注意这里不可用 k != i && l !=j 这样只统计了四个角的方块
                    }
                }
            }

            //进行周围八个邻居的判断：三活二不变其余死
            if (LiveNeibour == 3){
                NewArr[i][j] = 1;
            } else if (LiveNeibour == 2){
                NewArr[i][j] = Arr[i][j];
            } else {
                NewArr[i][j] = 0;
            }
        }
    }

    //将通过计算后得出的迭代后结果覆盖至原数组
    for (int i=1; i<19; i++){
        for (int j=1; j<61; j++){
            Arr[i][j] = NewArr[i][j];
        }
    }
}

int main(){

    cout << "Welcome to Conway's game of Life." << endl;
    cout << "This game uses a grid of size 20 by 60 in which" << endl;
    cout << "each cell can either be occupied by an organism or not." << endl;
    cout << "The occupied cells change from generation to generation" << endl;
    cout << "according to the number of neighboring cells which are alive." << endl;
    cout << "List the coordinates for living cells.(Input Format: x y)" << endl;
    cout << "Terminate the list with the special pair -1 -1" << endl;

    int Arr[20][62] = {0};

    //填充数据模块
    int a,b;
    while(1){
        cin >> a >> b;
        if(a == -1 && b == -1){
            break;
        }
        Arr[a][b] = 1;
    }

    //等待用户输入模块
    char choice;
    do{
        DrawInitGame(Arr);
        //在输出完本代图像后，提示用户进行下一步
        cout << "Continue viewing new generations?" << endl;
        cout << "(y,n)?" << endl;
        cin >> choice;
        if (choice == 'y'){
            Search(Arr);
        } else if(choice == 'n'){
            return 0;
        }
    } while (choice == 'y');
}