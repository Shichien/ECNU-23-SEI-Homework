//
// Created by Deralive (10235101526) on 2024/05/22.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include <iostream>
#include "Ordered_list.cpp"

using namespace std;

enum ErrorCode {
    Success,
    Not_Present
};

/* Pre: bottom and top define the range in the list to search for the target.
 Post: If a Record in the range of locations from bottom to top in the list has key equal to target , then position locates
one such entry and a code of Success is returned. Otherwise, the Error code of not present is
 returned and position becomes undefined.
 Uses: recursive_binary_1 and methods of the classes List and Record . */
ErrorCode recursive_binary_1(const Ordered_list &the_list, const Key &target, int bottom, int top, int &position) {
    Record data;
    if (bottom < top) { // List has more than one entry.
        int mid = (bottom + top) / 2;
        the_list.retrieve(mid, data);
        if (target > data) // Reduce to top half of list.
            return recursive_binary_1(the_list, target, mid + 1, top, position);
        else // Reduce to bottom half of list.
            return recursive_binary_1(the_list, target, bottom, mid, position);
    } else if (top < bottom)  // Can be remarked?
        return Not_Present; // List is empty.
    else { // List has exactly one entry.
        position = bottom;
        the_list.retrieve(bottom, data); // Retrieve the entry.
        if (data == target)              // Check for equality.
            return Success;              // Target found.
        else
            return Not_Present; // Target not present.
    }
}

/* Post: If a Record in the list has Key equal to target , then position locates
 one such entry and a code of Success is returned. Otherwise, Not_Present is returned and position is undefined.
 Uses: Methods for classes List and Record . */
ErrorCode binary_search_1(const Ordered_list &the_list, const Key &target, int &position) {
    Record data;
    int bottom = 0, top = the_list.size() - 1; // Initialize the range of the search.
    while (bottom < top) {
        int mid = (bottom + top) / 2; // Compute the midpoint.
        the_list.retrieve(mid, data); // Retrieve the entry at the midpoint.
        if (data < target)            // Reduce to the upper half.
            bottom = mid + 1;         // Set the new bottom.
        else
            top = mid; // Reduce to the lower half.
    }
    if (top < bottom)       // The list is empty.
        return Not_Present; // Target not present.
    else {
        position = bottom;               // Set the position of the target.
        the_list.retrieve(bottom, data); // Retrieve the entry.
        if (data == target)              // Check for equality.
            return Success;              // Target found.
        else
            return Not_Present; // Target not present.
    }
}

/* Pre: The indices bottom to top define the range in the list to search for the target .
 Post: If a Record in the range from bottom to top in the list has key equal to target , then position locates one such entry,
and a code of Success is returned. Otherwise, Not_Present is returned, and position is undefined.
 Uses: recursive_binary_2 , together with methods from the classes
 Ordered_list and Record . */
ErrorCode recursive_binary_2(const Ordered_list &the_list, const Key &target, int bottom, int top, int &position) {
    Record data;
    if (bottom <= top) // List has more than one entry.
    {
        int mid = (bottom + top) / 2; // Compute the midpoint.
        the_list.retrieve(mid, data); // Retrieve the entry at the midpoint.
        if (data == target)           // Check for equality.
        {
            position = mid; // Set the position of the target.
            return Success; // Target found.
        } else if (data < target)                                                  // Reduce to the upper half.
            return recursive_binary_2(the_list, target, mid + 1, top, position); // Set the new bottom.
        else
            return recursive_binary_2(the_list, target, bottom, mid - 1, position); // Reduce to the lower half.
    } else
        return Not_Present; // Target not present.
}

/* Post: If a Record in the list has key equal to target , then position locates
 one such entry and a code of Success is returned. Otherwise, not present is returned
 and position is undefined.
 Uses: Methods for classes Ordered_list and Record . */
ErrorCode binary_search_2(const Ordered_list &the_list, const Key &target, int &position) {
    Record data;                               // Temporary storage for the data.
    int bottom = 0, top = the_list.size() - 1; // Initialize the range of the search.
    while (bottom <= top)                      // The list has more than one entry.
    {
        position = (bottom + top) / 2;     // Compute the midpoint.
        the_list.retrieve(position, data); // Retrieve the entry at the midpoint.
        if (data == target)                // Check for equality.
            return Success;
        if (data < target) // Reduce to the upper half.
            bottom = position + 1;
        else                    // Reduce to the lower half.
            top = position - 1; // Set the new top.
    }
    return Not_Present; // Target not present.
}

// Post: The key of x has been printed.
void print(Record &x) {
    cout << x.the_key() << " "; // Output the key.
}

// Post: The methods recursive_binary_1, binary_search_1, recursive_binary_2, and binary_search_2 have been tested.
int main() {
    Key target(5);
    Ordered_list mylist;                     // A list to search.
    for (int i = 0; i < 10; i++)             // Insert the numbers 0 through 9.
        mylist.insert(Record(i, 10));        // Insert the number.
    cout << "The ordered list is: " << endl; // Output the list.
    mylist.traverse(print);                  // Output the list.
    cout << endl
         << "The target is: " << target.the_key() << endl; // Output the target.
    int bottom = 0;                                        // Initialize the range of the search.
    int top = mylist.size() - 1;                           // Initialize the range of the search.
    int position = -1;                                     // Position of the target.

    cout << endl
         << "Use recursive_binary_1 Method:" << endl;                         // Output the method name.
    if (recursive_binary_1(mylist, target, bottom, top, position) == Success) // Search for the target.
        cout << "Get the target in position: " << position << endl;           // Output the position.
    else
        cout << "Target not present." << endl; // Output the message.

    position = -1; // Position of the target.
    cout << endl
         << "Use binary_search_1 Method:" << endl; // Output the method name.
    if (binary_search_1(mylist, target, position) == Success)
        cout << "Get the target in position: " << position << endl; // Output the position.
    else
        cout << "Target not present." << endl; // Output the message.

    position = -1;
    cout << endl
         << "Use recursive_binary_2 Method:" << endl;                         // Output the method name.
    if (recursive_binary_2(mylist, target, bottom, top, position) == Success) // Search for the target.
        cout << "Get the target in position: " << position << endl;           // Output the position.
    else
        cout << "Target not present." << endl;

    position = -1; // Position of the target.
    cout << endl
         << "Use binary_search_2 Method:" << endl;
    if (binary_search_2(mylist, target, position) == Success)       // Search for the target.
        cout << "Get the target in position: " << position << endl; // Output the position.
    else
        cout << "Target not present." << endl; // Output the message.
    system("pause");
}