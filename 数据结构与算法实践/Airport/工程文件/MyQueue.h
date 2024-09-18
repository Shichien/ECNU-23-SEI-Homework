//
// Created by Deralive (10235101526) on 2024/03/23.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include"Plane.cpp"

enum Error_code {
    underflow, overflow, success, fail
};

const int maxqueue = 100; //  small value for testing

typedef Plane Queue_entry;


class MyQueue {

public:

    MyQueue();  // ���캯��

    bool empty() const; //�������Ƿ�Ϊ��

    Error_code serve(); //  �Ӷ�����ȡ��һ��Ԫ�أ����Ƴ���Ԫ��

    Error_code append(const Queue_entry &item); //  ������в���һ��Ԫ��

    Error_code retrieve(Queue_entry &item) const;   //    �Ӷ������������Ԫ�ز��������Ļ�ϣ������Ƴ���Ԫ��

    bool full() const;  // �������Ƿ�����

    int size() const;   // ��ʾ���������е�Ԫ�ظ���

    void clear();   //  ��������е�����Ԫ�أ��ָ�Ϊ��ʼ״̬

    Error_code serve_and_retrieve(Queue_entry &item);   //    �Ӷ������������Ԫ�ز��������Ļ�ϣ����Ƴ���Ԫ��

protected:

    int count;

    int front, rear;

    Queue_entry entry[maxqueue];

};