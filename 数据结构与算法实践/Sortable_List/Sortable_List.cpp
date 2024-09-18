//
// Created by Deralive (10235101526) on 2024/05/30.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Sortable_List.h"
#include <iostream>
#include <algorithm>
using namespace std;

// #include "MergeSortFromLinkedLists.h"

// void recursive_merge_sort(Node<Record> *&sub_list)
// {
//     if (sub_list != NULL && sub_list->next != NULL)
//     {
//         Node<Record> *second_half = divide_from(sub_list);
//         recursive_merge_sort(sub_list);
//         recursive_merge_sort(second_half);
//         sub_list = merge(sub_list, second_half);
//     }
// }

Node<Record> *divide_from(Node<Record> *sub_list)
/* Post: The list of nodes referenced by sub_list has been reduced to its first half, and a
 pointer to the first node in the second half of the sublist is returned. If the
 sublist has an odd number of entries, then its first half will be one entry larger
 than its second.*/
{
    Node<Record> *position, // traverses the entire list
        *midpoint,          // moves at half speed of position to midpoint
        *second_half;
    if ((midpoint = sub_list) == NULL)
        return NULL; // List is empty.
    position = midpoint->next;
    while (position != NULL)
    {                              // Move position twice for midpoint's one move.
        position = position->next; // Move position.
        if (position != NULL)
        {
            midpoint = midpoint->next; // Move midpoint.
            position = position->next; // Move position.
        }
    }
    second_half = midpoint->next; // Second half starts at midpoint's next.
    midpoint->next = NULL;        // Break list at midpoint.
    return second_half;           // Return pointer to second half.
}

Node<Record> *merge(Node<Record> *first, Node<Record> *second)
{
    Node<Record> *last_sorted; // points to the last node of sorted list
    Node<Record> combined;     // dummy first node, points to merged list
    last_sorted = &combined;
    while (first != NULL && second != NULL)
    { // Attach node with smaller key
        if (first->entry <= second->entry)
        {
            last_sorted->next = first; // Attach first to sorted list.
            last_sorted = first;       // Update last_sorted.
            first = first->next;       // Advance to the next unmerged node.
        }
        else
        {
            last_sorted->next = second; // Attach second to sorted list.
            last_sorted = second;       // Update last_sorted.
            second = second->next;      // Advance to the next unmerged node.
        }
    }
    // After one list ends, attach the remainder of the other.
    if (first == NULL)
        last_sorted->next = second; // Attach second to sorted list.
    else
        last_sorted->next = first; // Attach first to sorted list.
    return combined.next;
}

void Sortable_list ::swap(int low, int high)
{
    Record temp;
    retrieve(low, temp);       // Retrieve the low entry.
    replace(low, entry[high]); // Replace the low entry.
    replace(high, temp);       // Replace the high entry.
}

void Sortable_list ::quick_sort()
/* Post: The entries of the Sortable list have been
 rearranged so that their keys are sorted into
 nondecreasing order.
 Uses: Contiguous List implementation of Chapter 6,
 recursive quick sort .*/
{
    recursive_quick_sort(0, count - 1); // Sort the whole list.
}

void Sortable_list ::recursive_quick_sort(int low, int high)
/* Pre: low and high are valid positions in the Sortable list .
 Post: The entries of the Sortable list have been rearranged so that
 their keys are sorted into nondecreasing order.
 Uses: Contiguous List implementation of Chapter 6, recursive quick
 sort , and partition . */
{
    int pivot_position;
    if (low < high)
    {                                                   // Otherwise, no sorting is needed.
        pivot_position = partition(low, high);          // Sort low to high.
        recursive_quick_sort(low, pivot_position - 1);  // Sort first sublist.
        recursive_quick_sort(pivot_position + 1, high); // Sort second sublist.
    }
}

int Sortable_list ::partition(int low, int high)
/* Pre: low and high are valid positions of the Sortable list ,
with low <= high .
Post: The center (or left center) entry in the range between
indices low and high of the Sortable list has been chosen as a
pivot. All entries of the Sortable list between indices low and
high , inclusive, have been rearranged so that those with keys
less than the pivot come before the pivot and the remaining
entries come after the pivot. The final position of the pivot is
returned.
Uses: swap(int i, int j) (interchanges entries in positions i and j
of a Sortable list ), the contiguous List implementation of
Chapter 6, and methods for the class Record . */
{
    Record pivot;
    int i,          // used to scan through the list
        last_small; // position of the last key less than pivot
    swap(low, (low + high) / 2);
    pivot = entry[low]; // First entry is now pivot .
    last_small = low;
    for (i = low + 1; i <= high; i++) // Move entries less than pivot to front.
        if (entry[i] < pivot)
        {
            last_small++;        // Move the boundary of the pivot group.
            swap(last_small, i); // Move large entry to right and small to left.
        }
    swap(low, last_small); // Put the pivot into its proper position.
    return last_small;
}

void Sortable_list ::heap_sort()
/* Post: The entries of the Sortable list have been rearranged so that their keys
 are sorted into nondecreasing order.
 Uses: The contiguous List implementation of Chapter 6,build_heap , and insert_heap . */
{
    Record current;    // temporary storage for moving entries
    int last_unsorted; // Entries beyond last unsorted have been sorted.
    build_heap();      // First phase: Turn the list into a heap.
    for (last_unsorted = count - 1; last_unsorted > 0; last_unsorted--)
    {
        current = entry[last_unsorted];             // Extract last entry from list.
        entry[last_unsorted] = entry[0];            // Move top of heap to the end
        insert_heap(current, 0, last_unsorted - 1); // Restore the heap
    }
}

void Sortable_list ::insertion_sort()
/* Post: The entries of the Sortable list have been rearranged so that their keys are sorted into nondecreasing order.
 Uses: The contiguous List implementation of Chapter 6, and the class Record.*/
{
    int first_unsorted, position; // Index of first unsorted entry.
    Record current;               // Current entry to be inserted.
    for (first_unsorted = 1; first_unsorted < count; first_unsorted++)
    {
        if (entry[first_unsorted] < entry[first_unsorted - 1]) // current out of order.
        {
            current = entry[first_unsorted]; // Remove current from the list.
            position = first_unsorted;       // Initialize position.
            do
            {
                entry[position] = entry[position - 1]; // Shift entries to make room.
                position--;                            // Move to the next lower position.
            } while (position > 0 && entry[position - 1] > current); // Find the insertion point.
            entry[position] = current; // Insert current into the list.
        }
    }
}

void Sortable_list ::selection_sort()
/* Post: The entries of the Sortable list have been rearranged so that their keys are sorted into nondecreasing order.
 Uses: The contiguous List implementation of Chapter 6, max_key , and swap . */
{
    int last_unsorted, largest;                                         // Index of the last unsorted entry.
    for (last_unsorted = count - 1; last_unsorted > 0; last_unsorted--) // Do COUNT-1 times.
    {
        largest = max_key(0, last_unsorted); // Find the largest entry in the list.
        swap(largest, last_unsorted);        // Swap it with the last unsorted entry.
    }
}

int Sortable_list ::max_key(int low, int high)
/* Pre: low and high are valid positions in the Sortable list , with low <= high .
 Post: The index of the entry with the largest key between low and high is returned.
 Uses: The contiguous List implementation of Chapter 6. */
{
    int largest, current;                               // Index of the largest entry found so far.
    largest = low;                                      // Assume entry[low] is the largest.
    for (current = low + 1; current <= high; current++) // Look at the rest.
        if (entry[largest] < entry[current])            // Found a larger key.
            largest = current;                          // Remember its index.
    return largest;                                     // Return the index of the largest key found.
}

void Sortable_list ::sort_interval(int start, int increment)
/* Pre: 0 <= start < increment < count.
 Post: The entries of the Sortable list with indices that are multiples of increment between start and count - 1 have been rearranged so that their keys are sorted into nondecreasing order.
 Uses: The contiguous List implementation of Chapter 6, and the class Record.*/
{
    int i, j;                                              // Indices for the inner loop.
    Record current;                                        // The current entry to be inserted.
    for (i = start + increment; i < count; i += increment) // Do COUNT-1 times.
    {
        if (entry[i] < entry[i - increment]) // current out of order.
        {
            current = entry[i];                                                               // Remove current from the list.
            for (j = i; j - increment >= 0 && current < entry[j - increment]; j -= increment) // Find the insertion point.
                entry[j] = entry[j - increment];                                              // Shift entries to make room.
            entry[j] = current;                                                               // Insert current into the list.
        }
    }
}

void Sortable_list ::shell_sort()
/* Post: The entries of the Sortable list have been rearranged so that their keys are sorted into nondecreasing order.
 Uses: The contiguous List implementation of Chapter 6, and sort_interval . */
{
    int increment, start;                                      // Indices for the inner loop.
    for (increment = count / 2; increment > 0; increment /= 2) // Do COUNT/2 times.
        for (start = 0; start < increment; start++)            // Do increment times.
            sort_interval(start, increment);                   // Sort the sublist.
}

void Sortable_list ::insert_heap(const Record &current, int low, int high)
/* Pre: entry[low] through entry[high] form a heap.
 Post: current has been inserted into the heap formed by entry[low] through entry[high].
 Uses: The contiguous List implementation of Chapter 6. */
{
    int large;            // position of child of entry[low] with the larger key
    large = 2 * low + 1;  // large is now the left child of low.
    while (large <= high) // large is still in the array.
    {
        if (large < high && entry[large] < entry[large + 1]) // Compare left and right children.
            large++;                                         // large is now the child of low with the largest key.
        if (current >= entry[large])
            break; // current belongs in position low.
        else
        {                              // Promote entry[large] and move down the tree.
            entry[low] = entry[large]; // Move large up.
            low = large;               // Move low down.
            large = 2 * low + 1;       // large is now the left child of low.
        }
    }
    entry[low] = current; // Put current into its correct position.
}

void Sortable_list ::build_heap()
/* Post: The entries of the Sortable list have been rearranged so that
 it becomes a heap.
 Uses: The contiguous List implementation of Chapter 6, and insert
 heap . */
{
    int low;                                   // All entries beyond the position low form a heap.
                                               // 2K+1<=COUNT-1
    for (low = count / 2 - 1; low >= 0; low--) // Build a heap from the list.
    {                                          // Build a heap from the list.
        Record current = entry[low];           // Remove the top entry.
        insert_heap(current, low, count - 1);  // Add current to the heap.
    }
}

Node<Record> *Sortable_list::Get_head()
/* Post: The head pointer is returned.
 Uses: Nothing. */
{
    return head; // Return the head pointer.
}

void Mergesort(Sortable_list &mylist)
/* Post: The entries of the Sortable list have been rearranged so that their keys are sorted into nondecreasing order.
 Uses: The contiguous List implementation of Chapter 6, divide_from , and combine . */
{
    Sortable_list secondlist; // Second list for dividing.
    if (mylist.size() > 1)    // Otherwise, no sorting is needed.
    {
        divide_from(mylist, secondlist); // Divide the list into two sublists.
        Mergesort(mylist);               // Recursively sort the first sublist.
        Mergesort(secondlist);           // Recursively sort the second sublist.
        combine(mylist, secondlist);     // Merge the two sorted sublists.
    }
}

void divide_from(Sortable_list &mylist, Sortable_list &secondlist)
/* Post: The entries of the Sortable list have been divided into two sublists, with the second list in secondlist.
 Uses: The contiguous List implementation of Chapter 6. */
{
    int mid = (mylist.size() - 1) / 2;          // Midpoint of the list.
    int secondsize = mylist.size() - (mid + 1); // Size of the second list.
    for (int i = 0; i < secondsize; i++)        // Move entries from mylist to secondlist.
    {
        Record x;                                   // Entry to be moved.
        if (mylist.retrieve(mid + 1, x) == success) // Retrieve the entry.
        {                                           // Insert the entry into the second list.
            secondlist.insert(i, x);                // Insert the entry.
            mylist.remove(mid + 1, x);              // Remove the entry.
        }
    }
}

void combine(Sortable_list &firstsortlist, const Sortable_list &secondsortlist)
/* Post: The entries of the two sorted lists have been merged into a single sorted list.
 Uses: The contiguous List implementation of Chapter 6. */
{
    Sortable_list tmp;                                            // Temporary list for merging.
    int m = 0, n = 0, i = 0;                                      // Indices for the two lists and the merged list.
    while (m < firstsortlist.size() && n < secondsortlist.size()) // Neither list is empty.
    {
        Record x, y;                   // Entries to be compared.
        firstsortlist.retrieve(m, x);  // Retrieve the entries.
        secondsortlist.retrieve(n, y); // Retrieve the entries.
        if (x <= y)
        {
            tmp.insert(i++, x); // Insert the smaller entry.
            m++;                // Move to the next entry.
        }
        else
        {
            tmp.insert(i++, y); // Insert the smaller entry.
            n++;                // Move to the next entry.
        }
    }

    while (m < firstsortlist.size()) // The second list is empty.
    {
        Record x;                     // Entry to be moved.
        firstsortlist.retrieve(m, x); // Retrieve the entry.
        tmp.insert(i++, x);           // Insert the entry.
        m++;                          // Move to the next entry.
    }
    while (n < secondsortlist.size()) // The first list is empty.
    {
        Record y;                      // Entry to be moved.
        secondsortlist.retrieve(n, y); // Retrieve the entry.
        tmp.insert(i++, y);            // Insert the entry.
        n++;                           // Move to the next entry.
    }
    firstsortlist = tmp; // Copy the merged list back to the original list.
}