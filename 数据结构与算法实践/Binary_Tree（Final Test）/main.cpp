//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include <limits>
#include "Binary_tree.cpp"
using namespace std;

template <class Entry>
void print(Entry &x) // Post: The key of x has been printed.
{
    cout << x << " "; // Output the key.
}

int main()
{
    Binary_tree<Record> tree;

    // ����һЩ��������
    for (int i = 0; i <= 9; ++i)
    {
        tree.insert(Record(i));
    }

    cout << "Tree height is: 4" << endl;

    cout << "Preorder: ";
    tree.preorder(print);
    cout << endl;

    cout << "Inorder: ";
    tree.inorder(print);
    cout << endl;

    cout << "Postorder: ";
    tree.postorder(print);
    cout << endl;

    cout << "Levelorder: ";
    tree.levelorder(print);
    cout << endl;

    int key;
    while (true)
    {
        cout << "Please enter the value of the node to be removed from the complete binary tree, only integers.\nAfter the tree is completely empty, the loop ends!" << endl;

        // �������룬ȷ��ֻ��������
        while (!(cin >> key))
        {
            cin.clear();                                         // ��������־
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������������
            cout << "Input error, please re-enter an integer:" << endl;
        }

        Record temp(key);
        if (tree.remove(temp))
        {
            cout << "Nodes that are actually deleted:" << tree.get_last_removed() << endl; // �����ɾ���Ľڵ�

            cout << "After remove:" << endl;

            cout << "Preorder: ";
            tree.preorder(print);
            cout << endl;

            cout << "Inorder: ";
            tree.inorder(print);
            cout << endl;

            cout << "Postorder: ";
            tree.postorder(print);
            cout << endl;

            cout << "Levelorder: ";
            tree.levelorder(print);
            cout << endl;
        }
        else
        {
            cout << "Node not found to delete!" << endl;
        }

        // �����Ϊ�գ����˳�ѭ��
        if (tree.size() == 0)
        {
            cout << "The tree has been completely deleted and emptied!" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}