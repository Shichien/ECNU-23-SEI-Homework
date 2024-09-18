//
// Created by Deralive (10235101526) on 2024/06/04.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

class Key
{
    int key; // The key

public:
    Key(int x = 0);      // Constructor
    int the_key() const; // Return the key
};

bool operator==(const Key &x, const Key &y); // Compare two keys
