//
// Projected By Deralive (10235101526), release on 08/03/2024
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Stack.h"

/*
* Pre : None.
* Post: Initialize The Stack.
*/
Stack::Stack() {
    top_node = nullptr;
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
bool Stack::empty() const {
    return (top_node == nullptr);
}

/*
* Pre : The Stack Is Already Initialized, Less Than Stack's Maxsize.
* Post: Push The Item Into The Stack.
*/
Error_code Stack::push(const Node_entry& item) {
    Node* new_top = new Node(item, top_node);
    if (new_top == nullptr) {
        return Overflow; // ��ͷָ����Ϊ�գ�˵������ʧ��
        // cout << "The stack is overflow" << endl;
    }
    top_node = new_top; // ͷָ��ָ���¼����Ԫ��
    return Success;
}

/*
* Pre : The Stack Is Already Initialized, And At Lease One Item.
* Post: Pop The Top Item In The Stack.
*/
Error_code Stack::pop() {
    if (top_node == nullptr) {
        return Underflow;
    }
    else {
        Node* old_top = top_node; // ͷָ����ԭ��ͷָ��ָ�����һ���ڵ�
        top_node = old_top->next;
        delete old_top; // ɾ��ԭͷ����ָ�룬ģ��Ԫ�ر�ɾ��
        return Success;
    }
}

/*
* Pre : The Stack Is Already Initialized.
* Post: Output The Top Item In The Stack To User.
*/
Error_code Stack::top(Node_entry& item) const {
    if (top_node == nullptr) {
        // cout << "The stack is underflow!" << endl;
        return Underflow;
    }
    item = top_node->entry; // ��ȡ������Ϊ��ʱͷָ��ָ�������
    return Success;
}

// Safety features for linked structures
/*
* Pre : The Stack object exists.
* Post: All elements in the stack are removed, and memory associated with each node is deallocated.
*/
Stack::~Stack() {
    // ��������ʱ������ջԪ�ض��ᱻ�����.
    // ��������ڴ�й©���ڶ����������ڽ���ʱ���������ռ�õ���Դ.
    while (!empty()) {
        pop();
    }
}