//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Search_tree.h"

/* Pre: new_data is not already in the Search_tree.
 *  Post: If the key of new_data is not already in the Search_tree, then new_data is inserted into the tree in such a way that the properties of a binary search tree are preserved. Otherwise, a code of duplicate_error is returned.
 */
template <class Record>
Search_tree_errors Search_tree<Record>::insert(const Record &new_data)
{
    Search_tree_errors result = search_and_insert(this->root, new_data); // Call auxiliary function.
    if (result == success)                                               // Increment count if new_data was inserted.
        this->count++;                                                   // Count is a protected member of Binary_tree.
    return result;                                                       // Return result of search_and_insert.
}

/* Pre: new_data is not already in the Search_tree.
*  Post: If the key of new_data is not already in the Search_tree,
then new_data is inserted into the tree in such a way that the properties of a binary search tree are preserved.
Otherwise, a code of duplicate_error is returned.
*/
template <class Record>
Search_tree_errors Search_tree<Record>::search_and_insert(Binary_node<Record> *&sub_root, const Record &new_data)
{
    if (sub_root == NULL)
    {
        sub_root = new Binary_node<Record>(new_data); // Insert new_data at root.
        return success;                               // Return success to indicate new_data was inserted.
    }
    else if (new_data < sub_root->data)                      // Choose branch to follow.
        return search_and_insert(sub_root->left, new_data);  // Call recursively.
    else if (new_data > sub_root->data)                      // Choose branch to follow.
        return search_and_insert(sub_root->right, new_data); // Call recursively.
    else
        return duplicate_error; // new_data is already in tree.
}

/* Pre: None.
*  Post: If a Record with a key matching that of target belongs to the Search_tree,
a code of success is returned and the corresponding data is copied from the tree to target.
Otherwise, a code of not_present is returned.
*/
template <class Record>
Search_tree_errors Search_tree<Record>::tree_search(Record &target) const
{
    Search_tree_errors result = success;                              // Assume success.
    Binary_node<Record> *found = search_for_node(this->root, target); // Call auxiliary function.
    if (found == NULL)                                                // If target is not in tree,
        result = not_present;                                         // set result to not_present.
    else
        target = found->data; // Set target to data in node.
    return result;
}

/* Pre: None.
*  Post: If a Record with a key matching that of target belongs to the Search_tree,
* a code of success is returned and the corresponding data is copied from the tree to target.
Otherwise, a code of not_present is returned.
*/
template <class Record>
Binary_node<Record> *Search_tree<Record>::search_for_node(Binary_node<Record> *sub_root, const Record &target) const
{
    if (sub_root == NULL || sub_root->data == target)    // Base case.
        return sub_root;                                 // Return pointer to node containing target.
    else if (sub_root->data < target)                    // Choose branch to follow.
        return search_for_node(sub_root->right, target); // Recursively search right.
    else
        return search_for_node(sub_root->left, target); // Recursively search left.
}

// // Nonrecursive version:
// template <class Record>
// Binary_node<Record> *Search_tree<Record>::search_for_node(Binary_node<Record> *sub_root, const Record &target) const
// {
//     while (sub_root != NULL && sub_root->data != target)
//         if (sub_root->data < target)
//             sub_root = sub_root->right;
//         else
//             sub_root = sub_root->left;
//     return sub_root;
// }

/* Pre: None.
 *  Post: If the key of target is not in the subtree, a code of not_present is returned.
 * Otherwise, a code of success is returned and the subtree node containing target
 * has been removed in such a way that the properties of a binary search tree have been preserved.
 */
template <class Record>
Search_tree_errors Search_tree<Record>::search_and_destroy(Binary_node<Record> *&sub_root, const Record &target)
/* Post : If the key of target is not in the subtree,a code of not_present is returned.
*Otherwise,a code of success is returned and the subtree node containing target has been removed in such a way that the properties
of a binary search tree have been preserved.
Uses : Functions search and destroy recursively and remove root
*/
{
    if (sub_root == NULL || sub_root->data == target)
        return remove_root(sub_root);                      // Call auxiliary function.
    else if (target < sub_root->data)                      // Choose branch to follow.
        return search_and_destroy(sub_root->left, target); // Call recursively.
    else
        return search_and_destroy(sub_root->right, target); // Call recursively.
}

/* Pre: None.
 *  Post: If the key of target is not in the subtree, a code of not_present is returned.
 * Otherwise, a code of success is returned and the subtree node containing target
 * has been removed in such a way that the properties of a binary search tree have been preserved.
 */
template <class Record>
Search_tree_errors Search_tree<Record>::remove(const Record &target)
/* Post: If a Record with a key matching that of target
belongs to the Search tree a code of success is returned
and the corresponding node is removed from the
 tree. Otherwise, a code of not present is returned.
 Uses: Function search_and_destroy */
{
    Search_tree_errors result = search_and_destroy(this->root, target);
    if (result == success) // Decrement count if target was removed.
        this->count--;     // Count is a protected member of Binary_tree.
    return result;         // Return result of search_and_destroy.
}

/* Pre: None.
 *  Post: If the key of target is not in the subtree, a code of not_present is returned.
 * Otherwise, a code of success is returned and the subtree node containing target
 * has been removed in such a way that the properties of a binary search tree have been preserved.
 */
template <class Record>
Search_tree_errors Search_tree<Record>::remove_root(Binary_node<Record> *&sub_root)
{
    if (sub_root == NULL)
        return not_present;                    // Empty tree.
    Binary_node<Record> *to_delete = sub_root; // Node to delete.
    // Remember node to delete at end.
    if (sub_root->right == NULL)     // No right child.
        sub_root = sub_root->left;   // Replace root by left child.
    else if (sub_root->left == NULL) // No left child.
        sub_root = sub_root->right;  // Replace root by right child.
    else
    {                                           // Neither subtree is empty.
        to_delete = sub_root->left;             // Move left to find predecessor.
        Binary_node<Record> *parent = sub_root; // parent of to_delete
        while (to_delete->right != NULL)
        { // to_delete is not the predecessor.
            parent = to_delete;
            to_delete = to_delete->right;
        }
        sub_root->data = to_delete->data; // Move from to_delete to root.
        if (parent == sub_root)
            sub_root->left = to_delete->left; // Remove to_delete from tree.
        else
            parent->right = to_delete->left; // Remove to_delete from tree.
    }
    delete to_delete; // Remove to_delete from tree.
    return success;
}
