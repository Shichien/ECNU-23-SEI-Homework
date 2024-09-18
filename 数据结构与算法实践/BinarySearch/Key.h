//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Record.cpp"

class Key
{
	int key;

public:
	Key(int x = 0);		  // constructor
	Key(const Record &r); // constructor

	friend bool operator==(const Key &k1, const Key &k2);
	friend bool operator<(const Key &k1, const Key &k2);
	friend bool operator>(const Key &k1, const Key &k2);

	int the_key() const; // accessor
};