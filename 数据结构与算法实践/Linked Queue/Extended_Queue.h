//
// Created by Deralive (10235101526) on 2024/4/18.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include<iostream>
#include"Queue.cpp"

// ����ģ���࣬�̳�ʱҲҪ��ʽ��չ��ģ��
// ��ʹ��ģ�����ʱ��class Extended_Queue : public Queue {

template<class T>
class Extended_Queue : public Queue<T> {
public:
    int size() const; // �����еĴ�С����
    void clear();   // ���������
    State serve_and_retrieve(T& item); // ��ȡ��ǰ�˵�Ԫ�غ�ɾ����.
};