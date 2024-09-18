//
// Created by Deralive (10235101526) on 2024/06/13.
// Academic Contact: 10235101526 @ stu.ecnu.edu.cn
// Business Contact: Deralive @ 163.com / 2642136260 @ qq.com
//

#include "Binary_tree.h"
#include "Stack.cpp"
#include <queue>

template <class Entry>
Binary_tree<Entry>::Binary_tree()
/* Post: An empty binary tree has been created. */
{
    root = NULL; //  root is a pointer to the root of the binary tree.
    count = 0;   //  count is the number of entries in the binary tree.
}

template <class Entry>
bool Binary_tree<Entry>::empty() const
/* Post: A result oftrue is returned if the binary tree is empty.
Otherwise,false is returned. */
{
    return root == NULL; //  root is a pointer to the root of the binary tree.
}

template <class Entry>
void Binary_tree<Entry>::preorder(void (*visit)(Entry &))
{                                    //  visit is a function that processes the data in each node.
    recursive_preorder(root, visit); //  root is a pointer to the root of the binary tree.
}

template <class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))
{
    if (sub_root != NULL)
    {                                               //  sub_root is a pointer to the root of a subtree.
        (*visit)(sub_root->data);                   //  data is the data in the node to which sub_root points.
        recursive_preorder(sub_root->left, visit);  //  left is a pointer to the root of the left subtree of the node to which sub_root points.
        recursive_preorder(sub_root->right, visit); //  right is a pointer to the root of the right subtree of the node to which sub_root points.
    }
}

template <class Entry>
void Binary_tree<Entry>::inorder(void (*visit)(Entry &))
{
    recursive_inorder(root, visit); //  root is a pointer to the root of the binary tree.
}

template <class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))
{
    if (sub_root != NULL)
    {                                              //  sub_root is a pointer to the root of a subtree.
        recursive_inorder(sub_root->left, visit);  //  left is a pointer to the root of the left subtree of the node to which sub_root points.
        (*visit)(sub_root->data);                  //  data is the data in the node to which sub_root points.
        recursive_inorder(sub_root->right, visit); //  right is a pointer to the root of the right subtree of the node to which sub_root points.
    }
}

template <class Entry>
void Binary_tree<Entry>::postorder(void (*visit)(Entry &))
{
    recursive_postorder(root, visit); //  root is a pointer to the root of the binary tree.
}

template <class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))
{
    if (sub_root != NULL)
    {                                                //  sub_root is a pointer to the root of a subtree.
        recursive_postorder(sub_root->left, visit);  //  left is a pointer to the root of the left subtree of the node to which sub_root points.
        recursive_postorder(sub_root->right, visit); //  right is a pointer to the root of the right subtree of the node to which sub_root points.
        (*visit)(sub_root->data);                    //  data is the data in the node to which sub_root points.
    }
}

template <class Entry>
int Binary_tree<Entry>::size() const
{
    return count; //  count is the number of entries in the binary tree.
}

template <class Entry>
int Binary_tree<Entry>::height() const
{
    int count = size();            //  count is the number of entries in the binary tree.
    if (count == 0)                //  count is the number of entries in the binary tree.
        return 0;                  //  A result of 0 is returned.
    int tmp = 1;                   //  tmp is a temporary variable.
    int i;                         //  i is a counter.
    for (i = 0; tmp <= count; i++) //  tmp is a temporary variable.
        tmp *= 2;                  //  tmp is a temporary variable.
    return i;                      //  i is a counter.
}

template <class Entry>
void Binary_tree<Entry>::insert(const Entry &x)
{
    if (empty())
    {                                     //  A result of true is returned if the binary tree is empty. Otherwise, false is returned.
        root = new Binary_node<Entry>(x); //  root is a pointer to the root of the binary tree.
        count++;                          //  count is the number of entries in the binary tree.
        return;                           //  The function terminates.
    }
    Stack<int> numbers;    //  numbers is a stack of integers.
    int item = 0;          //  item is a temporary variable.
    int tmpcount = size(); //  tmpcount is a temporary variable.
    while (tmpcount > 0)
    { //  A result of true is returned if tmpcount is greater than 0. Otherwise, false is returned.
        if (tmpcount % 2 == 0)
        {                    // the node is right child
            numbers.push(2); // 2 stand for right child
        }
        else
        {                    // the node is left child
            numbers.push(1); // 1 stand for left child
        }
        tmpcount = (tmpcount - 1) / 2; // get to the parent
    }
    Binary_node<Entry> *current = root; //  current is a pointer to the root of the binary tree.
    while (numbers.size() > 1)
    {
        numbers.top(item);            //  item is a temporary variable.
        if (item == 1)                //  A result of true is returned if item is equal to 1. Otherwise, false is returned.
            current = current->left;  //  left is a pointer to the root of the left subtree of the node to which current points.
        if (item == 2)                //  A result of true is returned if item is equal to 2. Otherwise, false is returned.
            current = current->right; //  right is a pointer to the root of the right subtree of the node to which current points.
        numbers.pop();                //  The function terminates.
    }
    numbers.top(item);
    if (item == 1)
        current->left = new Binary_node<Entry>(x); //  left is a pointer to the root of the left subtree of the node to which current points.
    if (item == 2)
        current->right = new Binary_node<Entry>(x); //  right is a pointer to the root of the right subtree of the node to which current points.
    count++;
}

template <typename Entry>
void Binary_tree<Entry>::levelorder(void (*visit)(Entry &))
{
    if (root == nullptr)
        return;

    std::queue<Binary_node<Entry> *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        Binary_node<Entry> *currentNode = nodeQueue.front();
        nodeQueue.pop();

        visit(currentNode->data); // 对节点应用visit函数

        if (currentNode->left != nullptr)
            nodeQueue.push(currentNode->left);
        if (currentNode->right != nullptr)
            nodeQueue.push(currentNode->right);
    }
}

template <typename Entry>
Binary_node<Entry> *Binary_tree<Entry>::search(const Entry &Key)
{
    if (root == nullptr)
        return nullptr;

    std::queue<Binary_node<Entry> *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        Binary_node<Entry> *currentNode = nodeQueue.front();
        nodeQueue.pop();

        if (currentNode->data == Key)
            return currentNode;

        if (currentNode->left != nullptr)
            nodeQueue.push(currentNode->left);
        if (currentNode->right != nullptr)
            nodeQueue.push(currentNode->right);
    }
    return nullptr;
}

// 实现 remove 函数
template <typename Entry>
bool Binary_tree<Entry>::remove(const Entry &Key)
{
    if (root == nullptr)
        return false;

    Binary_node<Entry> *nodeToDelete = search(Key);
    if (nodeToDelete == nullptr)
        return false; // 没找到要删除的节点

    std::queue<Binary_node<Entry> *> nodeQueue;
    nodeQueue.push(root);
    Binary_node<Entry> *lastNode = nullptr;
    Binary_node<Entry> *parentOfLastNode = nullptr;

    Binary_node<Entry> *last_node = find_last_node();
    if (!last_node)
        return false; // 如果没有最后一个节点，返回 false

    last_removed = last_node->data; // 记录最后删除的节点

    while (!nodeQueue.empty())
    {
        lastNode = nodeQueue.front();
        nodeQueue.pop();

        if (lastNode->left != nullptr)
        {
            parentOfLastNode = lastNode;
            nodeQueue.push(lastNode->left);
        }
        if (lastNode->right != nullptr)
        {
            parentOfLastNode = lastNode;
            nodeQueue.push(lastNode->right);
        }
    }

    if (lastNode != nullptr && nodeToDelete != nullptr)
    {
        nodeToDelete->data = lastNode->data; // 用最后一个节点的数据替换要删除的节点

        if (parentOfLastNode->left == lastNode)
            parentOfLastNode->left = nullptr;
        else if (parentOfLastNode->right == lastNode)
            parentOfLastNode->right = nullptr;

        delete lastNode; // 删除最后一个节点
    }
    return true;
}

// 查找最后一个节点
template <class Entry>
Binary_node<Entry> *Binary_tree<Entry>::find_last_node() const
{
    if (!root)
        return nullptr;

    std::queue<Binary_node<Entry> *> q;
    q.push(root);
    Binary_node<Entry> *last_node = nullptr;

    while (!q.empty())
    {
        last_node = q.front();
        q.pop();

        if (last_node->left)
            q.push(last_node->left);
        if (last_node->right)
            q.push(last_node->right);
    }
    return last_node;
}

template <class Entry>
Entry Binary_tree<Entry>::get_last_removed() const
{
    return last_removed;
}
