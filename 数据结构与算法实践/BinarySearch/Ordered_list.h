//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "List.cpp"
#include "Key.cpp"

class Ordered_list : public List<Record> {

public:
    Error_code insert(const Record &data); // insert the data in the list
    Error_code insert(int position, const Record &data); // insert the data in the list
    Error_code replace(int position, const Record &data); // replace the data in the list
};