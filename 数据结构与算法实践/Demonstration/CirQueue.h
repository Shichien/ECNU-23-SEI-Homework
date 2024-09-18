//
// Created by Deralive (10235101526) on 2024/03/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#define MaxQueue 20  //  Smaller Value For Test.

enum State {
    Successful,
    Overqueue,
    Lessqueue,
};

template<class Type>
class CirQueue {

public:

    CirQueue(); // 构造函数
    State Append(Type Item);  //  向队列中插入一个元素
    State Serve();    //  从队列中取出一个元素，并移除该元素
    State Retrieve(Type &Item); //    从队列中输出顶部元素并输出到屏幕上，但不移除该元素
    void PrintQueue();  //  打印出所有的成员
    void TipTheSize();     // 显示队列中已有的元素个数
    bool EmptyQueue();    // 判断是否队列为空
    void Clear();    //  清除队列中的所有元素，恢复为初始状态
    // void Debug();

private:

    int Queue[MaxQueue];
    int Count;
    int Rear;
    int Front;
};