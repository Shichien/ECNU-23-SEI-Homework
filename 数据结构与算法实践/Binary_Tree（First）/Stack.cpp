//
// Projected By Deralive (10235101526), release on 08/03/2024
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Node.cpp"
#include "Stack.h"
#include <iostream>

using namespace std;

/*
 * Pre : None.
 * Post: Initialize The Stack.
 */
template <class T>
Stack<T>::Stack()
{
    top_node = nullptr; // ��ʼ��ջ��ͷָ��Ϊ��

    /* Node<T>* top_node �ڹ��캯���б�����Ϊ�ֲ���������������Ϊ���Ա����
     * ���캯��������top_node �ͻᱻ����
     * �����������Ա������Ȼ��ͼ���������ᵼ�� Segmentation Fault
     * �ڹ��캯���в�Ҫ����������Node<T>* top_node��ֱ�Ӷ����Ա���� top_node ����ʼֵ����
     */
}

/*
 * Pre : The Stack Is Already Initialized.
 * Post: Check The Stack Is Empty Or Not.
 */
template <class T>
bool Stack<T>::empty() const
{
    return (top_node == nullptr);
}

/*
 * Pre : The Stack Is Already Initialized, Less Than Stack's Maxsize.
 * Post: Push The Item Into The Stack.
 */
template <class T>
State Stack<T>::push(const T &Item)
{
    Node<T> *new_top = new Node<T>(Item, top_node);
    if (new_top == nullptr)
    { // ��ͷָ����Ϊ�գ�˵������ʧ��
        // cout << "The stack is overflow" << endl;
        return Overflow;
    }
    else
    {
        top_node = new_top; // ͷָ��ָ���¼����Ԫ��
        return Success;
    }
}

/*
 * Pre : The Stack Is Already Initialized.
 * Post: Output The Top Item In The Stack To User.
 */
template <class T>
State Stack<T>::top(T &Item) const
{
    if (top_node == nullptr)
    {
        // cout << "The stack is underflow!" << endl;
        return Underflow;
    }
    else
    {
        Item = top_node->data; // ��ȡ������Ϊ��ʱͷָ��ָ�������
        return Success;
    }
}

/*
 * Pre : The Stack Is Already Initialized, And At Lease One Item.
 * Post: Pop The Top Item In The Stack.
 */
template <class T>
State Stack<T>::pop()
{
    Node<T> *old_top = top_node;
    if (top_node == nullptr)
    {
        // cout << "The stack is empty!" << endl;
        return Underflow;
    }
    else
    {
        top_node = old_top->next; // ͷָ����ԭ��ͷָ��ָ�����һ���ڵ�
        delete old_top;           // ɾ��ԭͷ����ָ�룬ģ��Ԫ�ر�ɾ��
        return Success;
    }
}

/*
 * Pre : None.
 * Post: Return the top_node pointer.
 */
template <class T>
Node<T> *Stack<T>::GetTop() const
{
    return top_node; // ��ջΪ�գ��򷵻� nullptr.
}

/*
 * Pre : The Stack object exists.
 * Post: All elements in the stack are removed, and memory associated with each node is deallocated.
 */
template <class T>
Stack<T>::~Stack()
{
    // ��������ʱ������ջԪ�ض��ᱻ�����.
    // ��������ڴ�й©���ڶ����������ڽ���ʱ���������ռ�õ���Դ.
    while (!empty())
    {
        pop();
    }
}

template <class T>
int Stack<T>::size()
{
    Node<T> *temp = top_node;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}