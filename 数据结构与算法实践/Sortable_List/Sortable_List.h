//
// Created by Deralive (10235101526) on 2024/05/29.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "List.cpp"
#include "Key.cpp"
#include "Node.cpp"

class Sortable_list : public List<Record>
{
public:                    // Add prototypes for sorting methods here.
    void insertion_sort(); // sort the list by insertion sort.

    // for selection_sort.
    void swap(int low, int high);   // swap the low and high element.
    int max_key(int low, int high); // find the max key in the range of low to high.
    void selection_sort();          // sort the list by selection sort.

    // for shell_sort.
    void sort_interval(int start, int increment); // sort the list by interval.
    void shell_sort();                            // sort the list by shell sort.

    // for quick_sort.
    void quick_sort();                            // sort the list by quick sort.
    void recursive_quick_sort(int low, int high); // recursive quick sort.
    int partition(int low, int high);             // partition the list.

    // for heap_sort.
    void heap_sort();                                           // sort the list by heap sort.
    void build_heap();                                          // build the heap.
    void insert_heap(const Record &current, int low, int high); // insert the heap.

    Node<Record> *Get_head(); // get the head of the list.

private:                // Add prototypes for auxiliary functions here.
    Node<Record> *head; // the head of the list.
};

// for Mergesort
void divide_from(Sortable_list &mylist, Sortable_list &secondlist);              // divide the list from the secondlist.
void combine(Sortable_list &firstsortlist, const Sortable_list &secondsortlist); // combine the firstsortlist and secondsortlist.
void Mergesort(Sortable_list &mylist);                                           // sort the list by Mergesort.
