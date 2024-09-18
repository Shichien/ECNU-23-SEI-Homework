//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

enum Error_code
{
    underflow,
    overflow,
    Range_Error,
    success,
    fail
};

const int max_list = 30;

template <class List_entry>

class List
{

public:
    // methods of theList ADT

    List();

    int size() const; // returns the number of entries in the List

    bool full() const; // returns true or false according to whether the List is full or not

    bool empty() const; // returns true or false according to whether the List is empty or not

    void clear();

    void traverse(
        void (*visit)(List_entry &)); // applies the operation specified by function visit to each entry of the List

    Error_code
    retrieve(int position, List_entry &x) const; // retrieves the entry at position in the List and copies it to x

    Error_code replace(int position, const List_entry &x); // replaces the entry at position in the List with x

    Error_code remove(int position, List_entry &x); // removes the entry at position in the List and copies it to x

    Error_code insert(int position, const List_entry &x); // inserts x into the List at position

    // Node<List_entry> Get_head() {}
    // template <class List_entry>
    // Node<List_entry> *&List<List_entry>::Get_head()
    // {
    //     return head;
    // }

protected:
    // data members for a contiguous list implementation

    int count; // the number of entries in the List.

    List_entry entry[max_list]; // the array containing the List entries
};