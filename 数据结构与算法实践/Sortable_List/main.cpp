//
// Created by Deralive (10235101526) on 2024/05/30.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "Sortable_List.cpp"
using namespace std;

template <class List_entry> // The type of the entries in the list
void print(List_entry &x)
{
    cout << x; // Print the entry
}

int main()
{
    Sortable_list mylist;
    for (int i = 0; i < 10; i++)
        mylist.insert(i, Record(10 - i, 10)); // 10 9 8 7 6 5 4 3 2 1
    cout << "The list is: " << endl;
    mylist.traverse(print);

    cout << endl
         << "Use heap_sort Method:" << endl;
    mylist.heap_sort();     // 1 2 3 4 5 6 7 8 9 10
    mylist.traverse(print); // 10 9 8 7 6 5 4 3 2 1

    cout << endl
         << "Use quick_sort Method:" << endl;
    mylist.quick_sort();
    mylist.traverse(print);

    cout << endl
         << "Use Mergesort Method:" << endl;
    Mergesort(mylist);
    mylist.traverse(print);
    cout << endl
         << "Use insertion_sort Method:" << endl;
    mylist.insertion_sort();
    mylist.traverse(print);

    cout << endl
         << "Use selection_sort Method:" << endl;
    mylist.selection_sort();
    mylist.traverse(print);

    cout << endl
         << "Use shell_sort Method:" << endl;
    mylist.shell_sort();
    mylist.traverse(print);

    system("pause");
}
