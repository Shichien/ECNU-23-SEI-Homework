//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Ordered_list.cpp"
#include <iostream>

using namespace std;

template<class List_entry>
void print(List_entry &x) {
    cout << x;
}

int main() {

    Ordered_list mylist;
    int i;

    for (i = 0; i < 5; i++)
        mylist.insert(Record(i * 2));

    mylist.insert(Record(3));

    mylist.insert(0, Record(30));

    cout << "Your list have " << mylist.size() << " elements:" << endl;

    mylist.traverse(print);

    Record tmpRec(i);
    mylist.remove(0, tmpRec);

    cout << "After remove(0):" << endl;

    mylist.traverse(print);

    mylist.replace(0, Record(-1));

    cout << "After replace(0, Record(-1)):" << endl;

    mylist.traverse(print);

    cin.get();

    return 0;
}
