//
// Created by Deralive (10235101526) on 2024/4/6.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "Node.cpp"

using namespace std;

/*
 * Pre : After the user has entered the number of people and the number reported.
 * Post: Solve the Joseph problem and prompt the user which person was screened out,
 * and finally output the last remaining person.
 */
int SolveFunction(Node<int>* head, int count,int people) {
    if (!head || count<= 0) return -1; // ��ֹ������󣬵��³������г���

    Node<int>* NowPtr = head;
    while (NowPtr->next != NowPtr) {
        for (int i = 1; i < count - 1; i++) {
            NowPtr = NowPtr->next;
        }

        // ɾ���ڵ������
        Node<int>* temp = NowPtr->next;
        NowPtr->next = temp->next;
        cout << "Get rid of:" << (temp->data % people) + 1 << endl;
        delete temp;
        // �˴�ʹ��ȡ���1����Ϊ��ȷ�����������˵ļ��������ͬ

        NowPtr = NowPtr->next; // ���˴���ָ��������һ���ڵ�
    }

    int lastPerson = NowPtr->data;
    delete NowPtr; // �ͷ����һ���ڵ�
    cout << "The left element is:" ;
    return lastPerson + 1 ;
}

int main() {
    /*
     * Pre : None.
     * Post: Output prompt information and leave the header pointer blank.
     */
    Node<int>* head = nullptr;
    int people,count;
    cout << "This is a YSF problem." << endl;
    cout << "Please input two integers: (people , count)." << endl;
    cin >> people >> count ;

    /*
     * Pre : After the user has entered the number of people and the number reported.
     * Post: Creating a looped linked list using tail insertion method.
     */
    for (int i = 1; i <= people; ++i) {
        head = Node<int>::TailInsert(head, i);
    }

    /*
     * Pre : After the user has entered the number of people and the number reported.
     * Post: Solve the Joseph problem and prompt the user which person was screened out,
     * and finally output the last remaining person.
     */
    cout << SolveFunction(head, count, people) << endl;
    system("pause");
    return 0;
}