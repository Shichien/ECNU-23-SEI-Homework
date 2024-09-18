//
// Created by Deralive (10235101526) on 2024/05/16.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "List1.cpp"
using namespace std;

int main()
{
    List<int> mylist;
    for (int i = 0; i < 5; i++)                                         // Insert 5 elements
        mylist.insert(i, i);                                            // Insert i into the list at i
    cout << "Your list have " << mylist.size() << " elements:" << endl; // Output the size of the list
    mylist.traverse(print);                                             // Traverse the list and print the elements
    int i;                                                              // Define a variable i
    mylist.remove(1, i);                                                // Remove the element at position 1
    cout << "After remove(1):" << endl;                                 // Output the message
    mylist.traverse(print);                                             // Traverse the list and print the elements
    mylist.remove(0, i);                                                // Remove the element at position 0
    cout << "After remove(0):" << endl;                                 // Output the message
    mylist.traverse(print);                                             // Traverse the list and print the elements
    List<int> mylist2(mylist);                                          // Copy the list mylist to mylist2
    cout << "After mylist2(mylist):" << endl;                           // Output the message
    mylist2.traverse(print);                                            // Traverse the list and print the elements
    cout << "After update:" << endl;                                    // Output the message
    mylist.traverse(update);                                            // Traverse the list and update the elements
    mylist.traverse(print);                                             // Traverse the list and print the elements

    List<int> mylist3;                       // Define a new list mylist3
    mylist3 = mylist;                        // Copy the list mylist to mylist3
    cout << "After mylist3=mylist:" << endl; // Output the message
    mylist3.traverse(print);                 // Traverse the list and print the elements
    system("pause");
}
