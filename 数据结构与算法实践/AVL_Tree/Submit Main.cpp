//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "AVL_Tree.cpp"
#include "Record.cpp"
using namespace std;

// Post: The key of x has been printed.
void print(Record &x)
{
    cout << x.the_key() << " "; // Output the key.
}

int main()
{
    AVL_tree<Record> mytree;
    int value;
    int arr[200];
    int cir = 0;

    cout << "Please enter the value of the node to be inserted into the AVL tree, \n Notice: only integers can be entered. \n The input ends when -1 is entered." << endl;
    while (cin >> value && value != -1)
    {
        mytree.insert((Record)value);
        arr[cir++] = value;
    }

    cout << "AVL tree production is completed, the following output its pre-order, mid-order, post-order." << endl;

    // 执行和显示先序、中序、后序遍历结果
    cout << "Preorder:" << endl;
    mytree.preorder(print);
    cout << endl;

    cout << "Inorder:" << endl;
    mytree.inorder(print);
    cout << endl;

    cout << "Postorder:" << endl;
    mytree.postorder(print);
    cout << endl;

label:
    cout << "Please enter the value of the node to be removed from the AVL tree, only integers." << endl;
    int deleteValue;
    cin >> deleteValue;
    for (int i = 0; i < cir; i++)
    {
        if (arr[i] == deleteValue)
        {
            Record temp(deleteValue);
            mytree.remove(temp);

            cout << "After the node is deleted, output the pre-order, middle order, and post-order again." << endl;

            cout << "Preorder:" << endl;
            mytree.preorder(print);
            cout << endl;

            cout << "Inorder:" << endl;
            mytree.inorder(print);
            cout << endl;

            cout << "Postorder:" << endl;
            mytree.postorder(print);
            cout << endl;

            cout << "So what we're actually deleting is" << endl;
            cout << deleteValue << endl;

            system("pause");

            return 0;
        }
    }

    cout << "The entered value is not in the tree, please re-enter." << endl;
    goto label;
}
