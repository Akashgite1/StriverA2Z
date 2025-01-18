#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//!  ------------------------------ Binary Tree ---------------------------
//~ what is binary trees
//~ binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child.

//~ Binary Tree are Hierarchical Data Structures that use nodes to store data.
// binary tree structure its complte binary tree
//                   1
//                 /   \
//                2     3
//               / \   / \
//              4   5 6   7

//~ types of binary tree
//~ 1. Full Binary Tree: A binary tree is full if every node has 0 or 2 children.
//                   1 2
//                 /   \
//           2    2     3 2
//               / \   
//           0  4   5  0
//~ 2. Complete Binary Tree: A binary tree is complete if all levels are completely filled except possibly the last level and the last level has all keys as left as possible.
//                   1 2
//                 /   \
//           2    2     3 2
//               / \   /  \
//           0  4   5  0   7 0
//~ 3. Perfect Binary Tree: A binary tree is perfect if all internal nodes have two children and all leaves are at the same level.
//                   1 2
//                 /   \
//           2    2     3 2
//               / \   /  \
//           0  4   5  0   7 0
//~ 4. Balanced Binary Tree: A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes.
// n = 8   log 2 8 = 3  so the height of the tree is 3
//                   1 2
//                 /   \
//           2    2     3 2
//               / \   /  \
//           0  4   5  0   7 0

//~ Binary Tree Representation cpp code
// we use mostly use struct to represent the binary tree
// struct is a custom data type that we can create in c++
// for creatig a node in which we have left pointer and right pointer and the data
struct Node
{
    // data is where we store out values 
    int data;
    // left pointer to point the new left node
    struct Node *left;
    // right pointer to point the new right node 
    struct Node *right;

    // constructor to initialize the first nodes data and left and right pointer 
    // since its a root node currently there are no left and right node to point 
    // so our left and right pointer are pointing to null   
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//~ Binary Tree Traversal
// types of traversal
// 1. Inorder Traversal   : left -> root -> right
// 2. Preorder Traversal  : root -> left -> right
// 3. Postorder Traversal : left -> right -> root

//~ Inorder Traversal  : left -> root -> right
//! first we visit left subtree left child then its root then right child and then right subtree left child then its root then right child and the root node
// tree               1
//                  /   \
//                 2     3
//                / \   / \
//               4   5 6   7
// Inorder Traversal : 4 2 5 1 6 3 7

//~ Preorder Traversal   : root -> left -> right
//! first we visit the root node then left subtree left child then its root then right child and then right subtree left child then its root then right child
// tree               1
//                  /   \
//                 2     3
//                / \   / \
//               4   5 6   7
// Preorder Traversal : 1 2 4 5 3 6 7

//~ Postorder Traversal  : left -> right -> root
// first we visit left subtree left child then its root then right child and then right subtree left child then its root then right child and the root node
// tree               1
//                  /   \
//                 2     3
//                / \   / \
//               4   5 6   7
// Postorder Traversal : 4 5 2 6 7 3 1

//^ simple to remember the order of Traversal 
//! inorder : root at center 
//! preorder : root at first
//! postorder : root at last 

//~ Inorder Traversal cpp code
void inorder(struct Node *root)
{
    // if the root is null then return
    if (root == NULL)
    {
        return;
    }
    // first we visit the left child
    inorder(root->left);
    // then we visit the root node
    cout << root->data << " ";
    // then we visit the right child
    inorder(root->right);
}


int main()
{

    return 0;
}