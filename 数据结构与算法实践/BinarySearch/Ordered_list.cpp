//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Ordered_list.h"

/* Post: If the Ordered_list is not full, the function succeeds: The Record data
is inserted into the list, following the last entry of the list with a strictly lesser
key (or in the first list position if no list element has a lesser key).
Else: the function fails with the diagnostic Error_code overflow. */
Error_code Ordered_list::insert(const Record &data) {
    int s = size();                                 // size of the list
    int position;                                 // position to insert
    for (position = 0; position < s; position++) // find the position to insert
    {
        Record list_data;               // data in the list
        retrieve(position, list_data); // get the data in the list
        if (data < list_data)           // if the data is less than the list data
            break;
    }

    return List<Record>::insert(position, data); // insert the data
}

/* Post: If the Ordered list is not full, 0 <= position <= n , where n is the
number of entries in the list, and the Record data can be inserted at
position in the list, without disturbing the list order, then the function
succeeds: Any entry formerly in position and all later entries have their
position numbers increased by 1 and data is inserted atposition of the
List .
Else: the function fails with a diagnostic Error_code . */
Error_code Ordered_list::insert(int position, const Record &data) {
    Record list_data; // data in the list

    if (position > 0) {
        retrieve(position - 1, list_data); // get the data in the list
        if (data < list_data) // if the data is less than the list data
            return fail; // return fail
    }

    if (position < size()) {
        retrieve(position, list_data); // get the data in the list
        if (data > list_data) // if the data is greater than the list data
            return fail;
    }
    return List<Record>::insert(position, data); // insert the data
}

// replace the data in the list
Error_code Ordered_list::replace(int position, const Record &data) {

    if (position < 0 || position >= count) // if the position is out of range
        return Range_Error;
    Record list_data; // data in the list

    if (position > 0) {
        retrieve(position - 1, list_data); // get the data in the list
        if (data < list_data) // if the data is less than the list data
            return fail;
    }

    if (position < size() - 1) {
        retrieve(position + 1, list_data); // get the data in the list
        if (data > list_data) // if the data is greater than the list data
            return fail; // return fail
    }
    entry[position] = data; // replace the data
    return success;
}
