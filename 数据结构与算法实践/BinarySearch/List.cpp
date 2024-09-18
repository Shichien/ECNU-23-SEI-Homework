//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "List.h"

template<class List_entry>

/*Post: The List has been created and is initialized to be empty. */
List<List_entry>::List() {
    count = 0;
}

/* Post: The function returns the number of entries in the List . */
template<class List_entry>
int List<List_entry>::size() const {
    return count;
}

/*Post: The function returns true or false according to whether
the List is full or not. */
template<class List_entry>
bool List<List_entry>::full() const {
    return (count == max_list);
}

/*Post: The function returns true or false according to whether
the List is empty or not. */
template<class List_entry>
bool List<List_entry>::empty() const {
    return count == 0;
}

/*Post: All List entries have been removed; the List is empty.*/
template<class List_entry>
void List<List_entry>::clear() {
    count = 0;
}

/* Post: If the List is not full and 0 <= position <= n; where n is the number of
entries in the List , the function succeeds: Any entry formerly at position and
all later entries have their position numbers increased by 1 and x is inserted at
position of the List .
Else: The function fails with a diagnostic error code. */
template<class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x) {
    if (full())
        return overflow;
    if (position < 0 || position > count)
        return Range_Error;
    for (int i = count - 1; i >= position; i--)
        entry[i + 1] = entry[i];
    entry[position] = x;
    count++;
    return success;
}

/*Post: If 0<= position < n, where n is the number of entries in
the List, the function succeeds: The entry at position is
removed from the List, and all later entries have their
position numbers decreased by 1. The parameter x
records a copy of the entry formerly at position.
Else: The function fails with a diagnostic error code.*/
template<class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x) {
    if (empty())
        return underflow;
    if (position < 0 || position >= count)
        return Range_Error;
    x = entry[position];
    for (int i = position; i < count - 1; i++)
        entry[i] = entry[i + 1];
    count--;
    return success;
}

/*Post: If 0 <= position < n, where n is the number of entries
in the List, the function succeeds: The entry at position
is replaced by x; all other entries remain unchanged.
Else: The function fails with a diagnostic error code.*/
template<class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x) {
    if (position < 0 || position >= count)
        return Range_Error;
    entry[position] = x;
    return success;
}

/*Post: If 0 <= position < n, where n is the number of entries
in the List, the function succeeds: The entry at position
is copied to x; all List entries remain unchanged.
Else: The function fails with a diagnostic error code.*/
template<class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const {
    if (position < 0 || position >= count)
        return Range_Error;
    x = entry[position];
    return success;
}


/* Post: The action specified by function(*visit) has been performed on every entry of
theList , beginning at position 0 and doing each in turn. */
template<class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &)) {
    for (int i = 0; i < count; i++)
        (*visit)(entry[i]);
}
