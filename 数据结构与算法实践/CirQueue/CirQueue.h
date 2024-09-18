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

    CirQueue(); // ���캯��
    State Append(Type Item);  //  ������в���һ��Ԫ��
    State Serve();    //  �Ӷ�����ȡ��һ��Ԫ�أ����Ƴ���Ԫ��
    State Retrieve(Type &Item); //    �Ӷ������������Ԫ�ز��������Ļ�ϣ������Ƴ���Ԫ��
    void PrintQueue();  //  ��ӡ�����еĳ�Ա
    void TipTheSize();     // ��ʾ���������е�Ԫ�ظ���
    bool EmptyQueue();    // �ж��Ƿ����Ϊ��
    void Clear();    //  ��������е�����Ԫ�أ��ָ�Ϊ��ʼ״̬
    // void Debug();

private:

    int Queue[MaxQueue];
    int Count;
    int Rear;
    int Front;
};