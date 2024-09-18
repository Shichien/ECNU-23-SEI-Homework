//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Key.h"

Key::Key(int x) {
    key = x;
}

Key::Key(const Record &r) {
    key = r.the_key();
}

int Key::the_key() const {
    return key; // accessor
}

bool operator==(const Key &k1, const Key &k2) {
    return k1.key == k2.key;
}

bool operator<(const Key &k1, const Key &k2) {
    return k1.key < k2.key;
}

bool operator>(const Key &k1, const Key &k2) {
    return k1.key > k2.key;
}