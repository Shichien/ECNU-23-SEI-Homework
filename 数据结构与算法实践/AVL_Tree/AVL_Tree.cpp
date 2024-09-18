//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "AVL_Tree.h"

/*Post: If the key of new data is already in the AVL tree , a code of duplicate_error is returned.
 * Otherwise, a code of success is returned and the Record new data is inserted into the tree in such a way that
 * the properties of an AVL tree are preserved.
 * Uses: avl_insert.
 */
template <class Record>
AVL_Error AVL_tree<Record>::insert(const Record &new_data)
{
    bool taller;                                     // Has the tree grown in height?
    return avl_insert(this->root, new_data, taller); // Call auxiliary function.
}

/*Post: If the key of new data is already in the AVL tree , a code of duplicate_error is returned.
 * Otherwise, a code of success is returned and the Record new data is inserted into the tree in such a way that
 * the properties of an AVL tree are preserved.
 * Uses: avl_insert.
 */
template <class Record>
AVL_Error AVL_tree<Record>::avl_insert(Binary_node<Record> *&sub_root, const Record &new_data, bool &taller)
{
    AVL_Error result = AVL_success; // Assume success.
    if (sub_root == NULL)           // Insertion place found.
    {
        sub_root = new AVL_node<Record>(new_data); // Insert new_data at root.
        taller = true;                             // Tree height increases.
    }
    else if (new_data == sub_root->data) // Duplicate key.
    {
        result = AVL_duplicate_error; // Report duplicate key error.
        taller = false;               // Tree height does not increase.
    }
    else if (new_data < sub_root->data)
    {                                                          // Insert in left subtree.
        result = avl_insert(sub_root->left, new_data, taller); // Call recursively.
        if (taller == true)
            switch (sub_root->get_balance()) // Change balance factors.
            {                                // Change balance factors.
            case left_higher:
                left_balance(sub_root); // Left balance.
                taller = false;         // Rebalancing always shortens the tree.
                break;
            case equal_height:
                sub_root->set_balance(left_higher); // Now left higher.
                break;
            case right_higher:
                sub_root->set_balance(equal_height); // Now balanced.
                taller = false;                      // Rebalancing always shortens the tree.
                break;
            }
    }
    else
    {                                                           // Insert in right subtree.
        result = avl_insert(sub_root->right, new_data, taller); // Call recursively.
        if (taller == true)
            switch (sub_root->get_balance()) // Change balance factors.
            {
            case left_higher:
                sub_root->set_balance(equal_height); // Now balanced.
                taller = false;                      // Rebalancing always shortens the tree.
                break;
            case equal_height:
                sub_root->set_balance(right_higher); // Now right higher.
                break;
            case right_higher:
                right_balance(sub_root); // Right balance.
                taller = false;          // Rebalancing always shortens the tree.
                break;
            }
    }
    return result;
}

/*Pre: sub_root points to a subtree of the AVL tree . This subtree has a nonempty right subtree.
 * Post: sub_root is reset to point to its former right child, and the former sub_root
 * node is the left child of the new sub_root node.
 */
template <class Record>
void AVL_tree<Record>::rotate_left(Binary_node<Record> *&sub_root)
{
    if (sub_root == NULL || sub_root->right == NULL) // impossible cases
        cout << "WARNING: program error detected in rotate left" << endl;
    else
    {
        Binary_node<Record> *right_tree = sub_root->right; // right_tree is the right subtree of sub_root.
        sub_root->right = right_tree->left;                // left subtree of right_tree becomes right subtree of sub_root.
        right_tree->left = sub_root;                       // right_tree is the new root.
        sub_root = right_tree;                             // sub_root is the new root.
    }
}

/* Pre: sub_root points to a subtree of the AVL tree . This subtree has a nonempty left subtree.
 * Post: sub_root is reset to point to its former left child, and the former sub_root
 * node is the right child of the new sub_root node.
 */
template <class Record>
void AVL_tree<Record>::rotate_right(Binary_node<Record> *&sub_root)
{
    if (sub_root == NULL || sub_root->left == NULL) // impossible cases
        cout << "WARNING: program error detected in rotate right" << endl;
    else
    {
        Binary_node<Record> *left_tree = sub_root->left; // left_tree is the left subtree of sub_root.
        sub_root->left = left_tree->right;               // right subtree of left_tree becomes left subtree of sub_root.
        left_tree->right = sub_root;                     // left_tree is the new root.
        sub_root = left_tree;                            // sub_root is the new root.
    }
}

/* Pre: sub root points to a subtree of an AVL tree , doubly unbalanced on the right.
 * Post: The AVL properties have been restored to the subtree.
 * Uses: Methods of struct AVL node ; functions rotate_right ,rotate_left.
 */
template <class Record>
void AVL_tree<Record>::right_balance(Binary_node<Record> *&sub_root)
{
    Binary_node<Record> *&right_tree = sub_root->right; // right_tree is the right subtree of sub_root.
    switch (right_tree->get_balance())                  // Determine the balance of the right subtree.
    {
    case right_higher:                         // single rotation left
        sub_root->set_balance(equal_height);   // Reset balance factors.
        right_tree->set_balance(equal_height); // Reset balance factors.
        rotate_left(sub_root);                 // Perform single rotation left.
        break;
    case equal_height:                                             // impossible case because taller == true
        cout << "WARNING: program error in right balance" << endl; // Report error.
    case left_higher:                                              // double rotation left
        Binary_node<Record> *sub_tree = right_tree->left;          // sub_tree is the left subtree of right_tree.
        switch (sub_tree->get_balance())                           // Determine the balance of the left subtree.
        {
        case equal_height:
            sub_root->set_balance(equal_height);   // Reset balance factors.
            right_tree->set_balance(equal_height); // Reset balance factors.
            break;
        case left_higher: // T2 is h, T3 is h-1
            sub_root->set_balance(equal_height);
            right_tree->set_balance(right_higher);
            break;
        case right_higher: // T2 is h -1, T3 is h
            sub_root
                ->set_balance(left_higher);
            right_tree
                ->set_balance(equal_height);
            break;
        }
        sub_tree->set_balance(equal_height);
        rotate_right(right_tree); // Perform double rotation left.
        rotate_left(sub_root);    // Perform double rotation left.
        break;
    }
}

/* Pre: sub root points to a subtree of an AVL tree , doubly unbalanced on the left.
 * Post: The AVL properties have been restored to the subtree.
 * Uses: Methods of struct AVL node ; functions rotate_right ,rotate_left.
 */
template <class Record>
void AVL_tree<Record>::left_balance(Binary_node<Record> *&sub_root)
{
    Binary_node<Record> *&left_tree = sub_root->left; // left_tree is the left subtree of sub_root.
    switch (left_tree->get_balance())                 // Determine the balance of the left subtree.
    {
    case left_higher:                         // single rotation left
        sub_root->set_balance(equal_height);  // Reset balance factors.
        left_tree->set_balance(equal_height); // Reset balance factors.
        rotate_right(sub_root);               // Perform single rotation left.
        break;
    case equal_height: // impossible case
        cout << "WARNING: program error in right balance" << endl;
    case right_higher:                                    // double rotation left
        Binary_node<Record> *sub_tree = left_tree->right; // sub_tree is the right subtree of left_tree.
        switch (sub_tree->get_balance())                  // Determine the balance of the right subtree.
        {
        case equal_height:
            sub_root->set_balance(equal_height);
            left_tree->set_balance(equal_height);
            break;
        case right_higher:
            sub_root->set_balance(equal_height); // Reset balance factors.
            left_tree->set_balance(left_higher);
            break;
        case left_higher:
            sub_root->set_balance(right_higher);
            left_tree->set_balance(equal_height);
            break;
        }
        sub_tree->set_balance(equal_height); // Reset balance factors.
        rotate_left(left_tree);              // Perform double rotation left.
        rotate_right(sub_root);              // Perform double rotation left.
        break;
    }
}

/* Post: If the key of new data is not in the AVL tree , a code of AVL_not_present is returned.
 * Otherwise, a code of AVL_success is returned
 * and the Record new data is removed from the tree in such a way that the properties of an AVL tree are preserved.
 * Uses: avl_remove.
 */
template <class Record>
AVL_Error AVL_tree<Record>::remove(Record &new_data)
{
    bool shorter = true;                              // Has the tree shorter in height?
    return avl_remove(this->root, new_data, shorter); // Call auxiliary function.
}

template <class Record>
AVL_Error AVL_tree<Record>::avl_remove(Binary_node<Record> *&sub_root, Record &new_data, bool &shorter)
{
    AVL_Error result = AVL_success; // Assume success.
    Record sub_record;
    if (sub_root == NULL) // new_data is not in tree.
    {
        shorter = false;        // Tree is not shorter.
        return AVL_not_present; // Report failure.
    }
    else if (new_data == sub_root->data) // new_data is in tree.
    {
        Binary_node<Record> *to_delete = sub_root; // Remember node to delete at end.
        // Remember node to delete at end.
        if (sub_root->right == NULL) // Right subtree is empty.
        {
            sub_root = sub_root->left; // Remove to_delete from tree.
            shorter = true;            // Tree is shorter.
            delete to_delete;          // Remove to_delete from tree.
            return AVL_success;
        }
        else if (sub_root->left == NULL)
        {
            sub_root = sub_root->right; // Remove to_delete from tree.
            shorter = true;             // Tree is shorter.
            delete to_delete;           // Remove to_delete from tree.
            return AVL_success;         // Report success.
        }
        else
        {                               // Neither subtree is empty.
            to_delete = sub_root->left; // Move left to find predecessor.
            // Move left to find predecessor.
            Binary_node<Record> *parent = sub_root; // parent of to_delete
            // parent of to_delete
            while (to_delete->right != NULL)
            {
                // to_delete is not the predecessor.
                parent = to_delete;           // parent of to_delete
                to_delete = to_delete->right; // Move right.
            }
            // sub_root->data = to_delete->data; // Move data from to_delete to root.
            new_data = to_delete->data; // Move data from to_delete to root.
            sub_record = new_data;      // Move data from to_delete to root.
        }
    }
    if (new_data < sub_root->data)
    {                                                           // remove in left subtree.
        result = avl_remove(sub_root->left, new_data, shorter); // Call recursively.
        if (sub_record.the_key() != 0)                          // Move data from to_delete to root.
            sub_root->data = sub_record;                        // Move data from to_delete to root.
        // Move data from to_delete to root.
        if (shorter == true)                 // Rebalance if shorter.
            switch (sub_root->get_balance()) // Change balance factors.
            {                                // Change balance factors.
            case left_higher:
                sub_root->set_balance(equal_height); // Now balanced.
                break;
            case equal_height:
                sub_root->set_balance(right_higher); // Now right higher.
                shorter = false;
                break;
            case right_higher:
                shorter = right_balance2(sub_root); // Right balance.
                break;
            }
    }
    if (new_data > sub_root->data)
    {                                                            // remove in right subtree.
        result = avl_remove(sub_root->right, new_data, shorter); // Call recursively.
        if (sub_record.the_key() != 0)
            sub_root->data = sub_record; // Move data from to_delete to root.
        // Move data from to_delete to root.
        if (shorter == true)
            switch (sub_root->get_balance()) // Change balance factors.
            {                                // Change balance factors.
            case left_higher:
                shorter = left_balance2(sub_root); // Left balance.
                break;
            case equal_height:
                sub_root->set_balance(left_higher); // Now left higher.
                shorter = false;
                break;
            case right_higher:
                sub_root->set_balance(equal_height); // Now balanced.
                break;
            }
    }
    return result;
}

template <class Record>
bool AVL_tree<Record>::right_balance2(Binary_node<Record> *&sub_root)
/* Pre: sub root points to a subtree of an AVL tree , doubly unbalanced on the right.
 Post: The AVL properties have been restored to the subtree.
 Uses: Methods of struct AVL node ; functions rotate_right ,rotate_left . */
{
    bool shorter;                                       // Has the tree grown in height?
    Binary_node<Record> *&right_tree = sub_root->right; // right_tree is the right subtree of sub_root.
    switch (right_tree->get_balance())                  // Determine the balance of the right subtree.
    {
    case right_higher:                         // single rotation left
        sub_root->set_balance(equal_height);   // Reset balance factors.
        right_tree->set_balance(equal_height); // Reset balance factors.
        rotate_left(sub_root);                 // Perform single rotation left.
        shorter = true;
        break;
    case equal_height:                        // single rotation left
        right_tree->set_balance(left_higher); // Reset balance factors.
        rotate_left(sub_root);
        shorter = false; // Rebalancing always shortens the tree.
        break;
    case left_higher:                                     // double rotation left
        Binary_node<Record> *sub_tree = right_tree->left; // sub_tree is the left subtree of right_tree.
        switch (sub_tree->get_balance())
        {
        case equal_height:
            sub_root->set_balance(equal_height);   // Reset balance factors.
            right_tree->set_balance(equal_height); // Reset balance factors.
            break;
        case left_higher:
            sub_root->set_balance(equal_height);   // Reset balance factors.
            right_tree->set_balance(right_higher); // Reset balance factors.
            break;
        case right_higher:
            sub_root->set_balance(left_higher);    // Reset balance factors.
            right_tree->set_balance(equal_height); // Reset balance factors.
            break;
        }
        sub_tree->set_balance(equal_height); // Reset balance factors.
        rotate_right(right_tree);            // Perform double rotation left.
        rotate_left(sub_root);               // Perform double rotation left.
        shorter = true;                      // Rebalancing always shortens the tree.
        break;
    }
    return shorter;
}

template <class Record>
bool AVL_tree<Record>::left_balance2(Binary_node<Record> *&sub_root)
/* Pre: sub root points to a subtree of an AVL tree , doubly unbalanced on the left.
Post: The AVL properties have been restored to the subtree.
Uses: Methods of struct AVL node ; functions rotate_right ,rotate_left . */
{
    bool shorter;
    Binary_node<Record> *&left_tree = sub_root->left; // left_tree is the left subtree of sub_root.
    switch (left_tree->get_balance())                 // Determine the balance of the left subtree.
    {
    case left_higher:                         // single rotation left
        sub_root->set_balance(equal_height);  // Reset balance factors.
        left_tree->set_balance(equal_height); // Reset balance factors.
        rotate_right(sub_root);               // Perform single rotation left.
        shorter = true;                       // Rebalancing always shortens the tree.
        break;
    case equal_height:                        // single rotation left
        left_tree->set_balance(right_higher); // Reset balance factors.
        rotate_right(sub_root);               // Perform single rotation left.
        shorter = false;                      // Rebalancing always shortens the tree.
        break;
    case right_higher:                                    // double rotation left
        Binary_node<Record> *sub_tree = left_tree->right; // sub_tree is the right subtree of left_tree.
        switch (sub_tree->get_balance())                  // Determine the balance of the right subtree.
        {
        case equal_height:
            sub_root->set_balance(equal_height);  // Reset balance factors.
            left_tree->set_balance(equal_height); // Reset balance factors.
            break;
        case right_higher:
            sub_root->set_balance(equal_height);
            left_tree->set_balance(left_higher);
            break;
        case left_higher:
            sub_root->set_balance(right_higher);
            left_tree->set_balance(equal_height); // Reset balance factors.
            break;
        }
        sub_tree->set_balance(equal_height); // Reset balance factors.
        rotate_left(left_tree);              // Perform double rotation left.
        rotate_right(sub_root);              // Perform double rotation left.
        shorter = true;                      // Rebalancing always shortens the tree.
        break;
    }
    return shorter; // Rebalancing always shortens the tree.
}
