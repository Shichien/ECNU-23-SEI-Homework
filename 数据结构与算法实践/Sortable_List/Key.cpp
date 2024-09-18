//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Key.h"

Key::Key(int x)
// Post: The Key has been created with x as the key value.
{
    key = x; // constructor
}

Key::Key(const Record &r)
// Post: The Key has been created with the key value from r.
{
    key = r.the_key(); // constructor
}

int Key::the_key() const
// Post: Return the key value.
{
    return key; // accessor
}

bool operator==(const Key &k1, const Key &k2)
// Post: Return true if k1 and k2 have the same key value.
{
    return k1.key == k2.key; // comparison operators
}

bool operator<(const Key &k1, const Key &k2)
// Post: Return true if k1 has a smaller key value than k2.
{
    return k1.key < k2.key; // comparison operators
}

bool operator>(const Key &k1, const Key &k2)
// Post: Return true if k1 has a larger key value than k2.
{
    return k1.key > k2.key; // comparison operators
}

bool operator<=(const Key &k1, const Key &k2)
// Post: Return true if k1 has a larger key value than k2.
{
    return k1.key <= k2.key; // comparison operators
}

bool operator>=(const Key &k1, const Key &k2)
// Post: Return true if k1 has a larger key value than k2.
{
    return k1.key >= k2.key; // comparison operators
}