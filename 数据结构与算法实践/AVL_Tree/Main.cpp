#include <iostream>

#include "AVL_tree.cpp"

#include "Record.h"

template <class Entry>

void print(Entry &x)
{

	cout << x;
}

void main()
{

	AVL_tree<Record> mytree;

	mytree.insert(Record(13));

	mytree.insert(Record(5));

	mytree.insert(Record(16));

	mytree.insert(Record(3));

	mytree.insert(Record(10));

	mytree.insert(Record(14));

	mytree.insert(Record(18));

	mytree.insert(Record(2));

	mytree.insert(Record(4));

	mytree.insert(Record(8));

	mytree.insert(Record(11));

	mytree.insert(Record(15));

	mytree.insert(Record(17));

	mytree.insert(Record(20));

	mytree.insert(Record(1));

	mytree.insert(Record(7));

	mytree.insert(Record(9));

	mytree.insert(Record(12));

	mytree.insert(Record(19));

	mytree.insert(Record(6));

	cout << "Preorder:" << endl;

	mytree.preorder(print);

	cout << endl;

	cout << "inorder:" << endl;

	mytree.inorder(print);

	cout << endl;

	cout << "Postorder:" << endl;

	mytree.postorder(print);

	cout << endl
		 << endl;

	Record tmp(16);

	mytree.remove(tmp);

	cout << "Preorder:" << endl;

	mytree.preorder(print);

	cout << endl;

	cout << "inorder:" << endl;

	mytree.inorder(print);

	cout << endl;

	cout << "Postorder:" << endl;

	mytree.postorder(print);

	cout << endl
		 << endl;

	cout << tmp.the_key();

	cin.get();
}