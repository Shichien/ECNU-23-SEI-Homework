//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "Binary_tree.cpp"
#include "Record.cpp"
using namespace std;

template <class Entry>
void print(Entry &x) // Post: The key of x has been printed.
{
    cout << x; // Output the key.
}

int main()
{
    Binary_tree<Record> mytree;
    for (int i = 0; i < 10; i++) // Insert 10 records into the tree.
    {
        Record rec(i);
        mytree.insert(rec); // Insert the record into the tree.
    }
    cout << "Tree size is: " << mytree.size() << endl;     // Output the size of the tree.
    cout << "Tree height is: " << mytree.height() << endl; // Output the height of the tree.
    cout << "Preorder:" << endl;                           // Output the preorder traversal of the tree.
    mytree.preorder(print);
    cout << endl;
    cout << "inorder:" << endl;
    mytree.inorder(print);
    cout << endl;
    cout << "Postorder:" << endl;
    mytree.postorder(print);
    cout << endl;
    cin.get();
}
