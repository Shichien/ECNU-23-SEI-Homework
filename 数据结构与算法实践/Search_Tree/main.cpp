//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "Search_tree.cpp"
#include "Record.cpp"

using namespace std;

// Post: The key of x has been printed.
void print(Record &x)
{
    cout << x.the_key() << " "; // Output the key.
}

int main()
{
    Search_tree<Record> mytree; // Create a binary search tree.
    mytree.insert(Record(2));
    mytree.insert(Record(4));
    mytree.insert(Record(1));
    mytree.insert(Record(3));
    cout << "Tree size is: " << mytree.size() << endl;
    cout << "Preorder:" << endl;
    mytree.preorder(print);
    cout << endl;
    cout << "Inorder:" << endl;
    mytree.inorder(print);
    cout << endl;
    cout << "Postorder:" << endl;
    mytree.postorder(print);
    cout << endl;
    mytree.remove(Record(4));
    cout << "Tree size is: " << mytree.size() << endl;
    cout << "Preorder:" << endl;
    mytree.preorder(print);
    cout << endl;
    cout << "Inorder:" << endl;
    mytree.inorder(print);
    cout << endl;
    cout << "Postorder:" << endl;
    mytree.postorder(print);
    cout << endl;
    system("pause");
    return 0;
}
