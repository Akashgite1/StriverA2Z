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

//~ Preorder Traversal cpp code
void preorder(struct Node *root)
{
    // if the root is null then return
    if (root == NULL)
    {
        return;
    }
    // first we visit the root node
    cout << root->data << " ";
    // then we visit the left child
    preorder(root->left);
    // then we visit the right child
    preorder(root->right);
}

//~ Postorder Traversal cpp code
void postorder(struct Node *root)
{
    // if the root is null then return
    if (root == NULL)
    {
        return;
    }
    // first we visit the left child
    postorder(root->left);
    // then we visit the right child
    postorder(root->right);
    // then we visit the root node
    cout << root->data << " ";
}

//! breath first search or level order traversal
// level order traversal is a tree traversal algorithm that visits all the nodes of a tree level by level
//~ Level Order Traversal
//~ Level Order Traversal cpp code
vector<vector<int>> levelOrder(struct Node *root)
{
    vector<vector<int>> ans;

    if (root == NULL)
    {
        return ans;
    }

    // creating tree size queue to store the nodes
    //& This queue is dynamically sized and grows as needed to accommodate the nodes during the construction of the binary tree.
    queue<struct Node *> q;

    // push the root node to the queue
    q.push(root);

    // while the queue is not empty
    while (!q.empty())
    {
        // we can direct give the size two since its keep changing so we have first
        // declare the size variable and store the size of the queue
        int size = q.size();
        // vector to store the nodes at each level
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            // making a pointer to point the front element in the queue
            struct Node *node = q.front();
            // pop the front element from the queue
            q.pop();
            // push the data of the node that store in the queue since we store direct node
            // queue has the pointer to the node so we have to get the data of the node

            level.push_back(node->data);
            // we are pushing the node not its data
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }

        ans.push_back(level);
    }
    return ans;
}

//! iterative traversal
//~ Iterative Inorder Traversal
vector<int> inorderTraversal(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        curr = curr->right;
    }
    return ans;
}

//! Iterative Preorder Traversal
vector<int> preorderTraversal(struct Node *root)
{
    vector<int> ans;
    stack<struct Node *> st;
    struct Node *curr = root;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            ans.push_back(curr->data);
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        curr = curr->right;
    }
    return ans;
}

//! Iterative Postorder Traversal using one stack
vector<int> postorderTraversal(struct Node *root)
{
    vector<int> ans;
    stack<struct Node *> st;
    struct Node *curr = root;
    struct Node *prev = NULL;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        if (curr->right == NULL || curr->right == prev)
        {
            ans.push_back(curr->data);
            st.pop();
            prev = curr;
            curr = NULL;
        }
        else
        {
            curr = curr->right;
        }
    }
    return ans;
}

//! Iterative Postorder Traversal using two stack
vector<int> postorderTraversal_Iterative(struct Node *root)
{

    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<struct Node *> st1;
    stack<struct Node *> st2;
    st1.push(root);
    while (!st1.empty())
    {
        struct Node *curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left != NULL)
        {
            st1.push(curr->left);
        }
        if (curr->right != NULL)
        {
            st1.push(curr->right);
        }
    }
    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}
//! calculate the number of nodes at each level
int LevelNode(int i)
{

    // 2^i we return since the number of nodes at each level is 2^i
    return pow(2, i);

    // tree            1        level 0
    //               /   \
    //              2     3     level 1
    //             / \   / \
    //            4   5 6   7   level 2
    // 2^0 = 1 her we are following the 0 based index so the level 0 has 1 node
    // we can use bit manipulation to calculate the 2^i
    // return 1 << i;  if we follow the 1 based indexing we can return 1 << (i-1)
}

//! Height of the binary tree
// 104. Maximum Depth of Binary Tree
//                        3
//                     /   \
//                    9     20
//                         /   \
//                        15    7
// height of the tree is 3 since the longest path from the root to the leaf node is 3
int height(struct Node *root)
{
    //~ recuresive approach to calculate the height of the binary tree
    // if (root == NULL)
    // {
    //     return 0;
    // }
    // int left = height(root->left);
    // int right = height(root->right);
    // return max(left, right) + 1;
    // +1 if we considering the 1base indexing
    // return max(left, right); its ok if we considering the 0 based indexing

    //~ using the breath first search and dfs depth first search (BFS)
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;

    queue<Node *> que;
    que.push(root);

    int depth = 1;

    while (!que.empty())
    {
        int n = que.size();

        while (n--)
        {
            Node *temp = que.front();
            que.pop();

            if (!temp->left && !temp->right)
                return depth;

            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }

        depth++;
    }

    return -1;
}

//! Diameter of the binary tree
class Solution
{
public:
    int solve(Node *root, int &result)
    {

        // condition to stop
        if (!root)
            return 0;
        int leftH = solve(root->left, result);
        int rightH = solve(root->right, result);

        result = max(result, leftH + rightH);

        return max(leftH, rightH) + 1;
    }

    int diameterOfBinaryTree(Node *root)
    {
        int result = 0;

        if (root == NULL)
            return 0;

        solve(root, result);

        return result;
    }
    // TC O(n) SC O(1)
};

//! 110. Balanced Binary Tree
//~ Given a binary tree, determine if it is height-balanced.
//                     3
//                   /   \
//                  9     20
//                      /   \
//                     15    7        ans : true
// return true since the height of the left subtree and right subtree is not more than 1
class Balanced
{
public:
    int height(Node *root)
    {
        if (!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(Node *root)
    {
        return height(root) != -1;
    }
};

//! 103. Binary Tree Zigzag Level Order Traversal
//                        3
//                     /   \
//                    9     20
//                         /   \
//                        15    7
// zigzag level order traversal   [[3],[20,9],[15,7]]
vector<vector<int>> zigzagLevelOrder(Node *root)
{
    if (!root)
        return {}; // Return empty if the tree is empty

    vector<vector<int>> result; // Final result
    queue<Node *> q;            // Queue for BFS
    q.push(root);
    bool leftToRight = true; // Direction flag

    while (!q.empty())
    {
        int size = q.size();
        deque<int> level; // Use deque to handle zigzag order

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            // direction is left to right
            if (leftToRight)
            {
                level.push_back(node->data); // Add to the end
            }
            else
            {
                level.push_front(node->data); // Add to the front for reverse order
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        result.push_back(vector<int>(level.begin(), level.end())); // Convert deque to vector
        leftToRight = !leftToRight;                                // Toggle direction
    }

    return result;
}

//! 124. Binary Tree Maximum Path Sum
class maxPathSumClass
{
public:
    int maxpath(Node *node, int &maxi)
    {
        if (node == NULL)
            return 0;

        // we provide the 2 parameters inside the max one is 0 and another one is
        // recursion of maxpath is the recursion of maxpath provide the negative value
        // we will return 0 insted of taking that negative value
        // since the negative value never provide as the max sum
        int left = max(0, maxpath(node->left, maxi));

        int right = max(0, maxpath(node->right, maxi));

        maxi = max(maxi, left + right + node->data);

        return max(left, right) + node->data;
    }
    // main function
    int maxPathSum(Node *root)
    {
        int maxi = INT_MIN;

        maxpath(root, maxi);
        return maxi;
    } // TC O(n) SC O(1)
};

//! check if two binary tree are similar or not
//~ 100. Same Tree
bool isSameTree(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->data != q->data)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//! boundary traversal of the binary tree
//~ 545. Boundary of Binary Tree
class boundary
{
public:
    void leftBoundary(Node *root, vector<int> &ans)
    {
        // if the root is null then return
        if (!root)
            return;
        // if the left child is present then push the data of the root node
        if (root->left)
        {
            ans.push_back(root->data);
            // visit next left child if present
            leftBoundary(root->left, ans);
        }
        else if (root->right)
        {
            ans.push_back(root->data);
            leftBoundary(root->right, ans);
        }
        // store elements upto the leaf node
    }

    void rightBoundary(Node *root, vector<int> &ans)
    {
        // if the root is null then return
        if (!root)
            return;
        // if the right child is present then push the data of the root node
        if (root->right)
        {
            ans.push_back(root->data);
            // visit next right child if present
            rightBoundary(root->right, ans);
        }
        else if (root->left)
        {
            ans.push_back(root->data);
            rightBoundary(root->left, ans);
        }
    }

    void leaves(Node *root, vector<int> &ans)
    {
        // if the root is null then return
        if (!root)
            return;
        // check if the node left and right child are null
        // if yes then its a leaf node since leaf node has no child
        if (!root->left && !root->right)
        {
            ans.push_back(root->data);
            return;
        }
        // visit the left and right child if present
        leaves(root->left, ans);
        leaves(root->right, ans);
    }

    vector<int> boundaryOfBinaryTree(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        ans.push_back(root->data);
        leftBoundary(root->left, ans);
        leaves(root->left, ans);
        leaves(root->right, ans);
        rightBoundary(root->right, ans);
        return ans;
    }
};

//! vertical order traversal of the binary tree
//~ 987. Vertical Order Traversal of a Binary Tree
vector<vector<int>> verticalTraversal(Node *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        mp[x][y].insert(node->data);
        if (node->left)
            q.push({node->left, {x - 1, y + 1}});
        if (node->right)
            q.push({node->right, {x + 1, y + 1}});
    }

    vector<vector<int>> ans;
    for (auto x : mp)
    {
        vector<int> temp;
        for (auto y : x.second)
        {
            for (auto z : y.second)
            {
                temp.push_back(z);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

//! Top View of the binary tree using Level Order Traversal
class Top_View
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {

        // declaring vector for storing the answer
        vector<int> ans;

        // if root is null return ans
        if (root == NULL)
            return ans;

        // map store the element in sorted oreder
        map<int, int> mpp;

        // queue for storing node and its order
        queue<pair<Node *, int>> q;

        // push the root and its level into queue
        q.push({root, 0});

        while (!q.empty())
        {

            // pointer to the queue front element
            auto it = q.front();
            // remove the pointed element from the queue
            q.pop();

            // poiting the stored queue node which is a tree node since we
            // are storing pair of node and int in queue
            Node *node = it.first;

            // poiting the line storing with the node in the queue
            int line = it.second;

            // put the line and data or the node value into map only if
            // there are not present in the map first
            if (mpp.find(line) == mpp.end())
            {
                mpp[line] = node->data;
            }

            // add selected node left and right node into queue with line
            // for left we are sending line-1
            if (node->left != NULL)
                q.push({node->left, line - 1});
            // for right we are sending l(ine +1
            if (node->right != NULL)
                q.push({node->right, line + 1});
        }

        // store the map element into vector for declaring answer
        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

//! Bottom View of Binary Tree
class Bottom_View
{
public:
    vector<int> bottomView(Node *root)
    {

        // declaring the vector for answer
        vector<int> ans;

        // if root is null return  ans
        if (root == NULL)
            return ans;

        // map to store the element in sorted order
        map<int, int> mpp;
        // queue for storing the node and its order
        queue<pair<Node *, int>> q;
        // push the root and its line into queue
        q.push({root, 0});
        // while the queue is not empty
        while (!q.empty())
        {
            // pointer to the front element of the queue
            auto it = q.front();
            // remove the front element from the queue
            q.pop();
            // point the node and line of the node
            Node *node = it.first;
            // line of the node
            int line = it.second;
            // put the line and data of the node into map
            mpp[line] = node->data;

            // push the left and right child of the node into queue
            if (node->left != NULL)
                q.push({node->left, line - 1});
            if (node->right != NULL)
                q.push({node->right, line + 1});
        }
        // store the map element into vector for declaring answer
        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

//! 199. Binary Tree Right Side View
class Right_Side_View
{
public:
    // recursive function
    void recursion(Node *root, int level, vector<int> &res)
    {
        // base case
        if (root == NULL)
            return;
        if (res.size() == level)
            res.push_back(root->data);
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }
    vector<int> rightSideView(Node *root)
    {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};

//! 101. Symmetric Tree
class Symmetric
{
public:
    bool symmetricReccursion(Node *left, Node *right)
    {
        // if both are null return true if one of them are null return false
        if (left == NULL || right == NULL)
            return left == right;

        // if current node of left and right is not equal return false
        if (left->data != right->data)
            return false;

        return symmetricReccursion(left->left, right->right) &&
               symmetricReccursion(left->right, right->left);
    }
    bool isSymmetric(Node *root)
    {
        return root == NULL || symmetricReccursion(root->left, root->right);
    }
};

//!

int main()
{
    //~ struct is the name of custom data structure
    //~ Node is the name of the structure which used to access the data
    //~ root is the name and the pointer to new node or data created using
    //~ the struct data structure
    //~ new keyword is used to create a new data from the struct data structure

    //! creating a root node
    // struct Node *root = new Node(1); // 1
    // creating left and right child of the root node
    // root->left = new Node(2);
    // root->right = new Node(3);                    // 1
    // /   \
                                                  // 2     3
    // creating left and right child of the left child of the root node
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);            // 1
    // /   \
                                                 // 2     3
    // / \
                                               // 4   5
    // creating left and right child of the right child of the root node
    // root->right->left = new Node(6);              // 1
    // root->right->right = new Node(7);           // /   \
                                                  // 2     3
    // / \    / \
                                                // 4   5 6   7

    //!                        Binary Traversal

    //! Inorder Traversal : left -> root -> right
    // inorder(root);
    // cout << endl;

    //! Preorder Traversal : root -> left -> right
    // preorder(root);
    // cout << endl;

    //! Postorder Traversal : left -> right -> root
    // postorder(root);
    // cout << endl;

    //! Level Order Traversal
    // vector<vector<int>> ans = levelOrder(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //! Iterative Inorder Traversal
    // vector<int> ans = inorderTraversal(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    //! Iterative Preorder Traversal
    // vector<int> ans = preorderTraversal(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    //! Iterative Postorder Traversal using one stack
    // vector<int> ans = postorderTraversal(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    //! Iterative Postorder Traversal using two stack
    // vector<int> ans = postorderTraversal(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    //! calculate the number of nodes at each level
    // cout << LevelNode(6) << endl;

    //! height of the binary tree
    // cout << height(root) << endl;

    //! diameter of the binary tree
    //         tree contructed
    //                1
    //              /   \
    //             2     3
    //            / \   
    //           4   5
    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // Solution s;
    // cout << s.diameterOfBinaryTree(root) << endl;

    //! 110. Balanced Binary Tree
    // struct Node *root = new Node(3);
    // root->left = new Node(9);
    // root->right = new Node(20);
    // root->right->left = new Node(15);
    // root->right->right = new Node(7);
    // Balanced b;
    // if(b.isBalanced(root)){
    //    cout << "yes the tree is balanced" << endl;
    // }else{
    //     cout << "false" << endl;
    // }

    //! 103. Binary Tree Zigzag Level Order Traversal
    // struct Node *root = new Node(3);
    // root->left = new Node(9);
    // root->right = new Node(20);
    // root->right->left = new Node(15);
    // root->right->right = new Node(7);
    // vector<vector<int>> ans = zigzagLevelOrder(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //! 124. Binary Tree Maximum Path Sum
    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // Solution s;
    // cout << s.maxPathSum(root) << endl;

    //! 100. Same Tree
    // struct Node *p = new Node(1);
    // p->left = new Node(2);
    // p->right = new Node(3);
    // struct Node *q = new Node(1);
    // q->left = new Node(2);
    // q->right = new Node(3);
    // if(isSameTree(p,q)){
    //     cout << "yes the tree is same" << endl;
    // }else{
    //     cout << "no the tree is not same" << endl;
    // }

    //! 545. Boundary of Binary Tree
    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->left->left = new Node(3);
    // root->left->right = new Node(4);
    // root->left->right->left = new Node(5);
    // root->left->right->right = new Node(6);
    // root->right = new Node(7);
    // root->right->left = new Node(8);
    // root->right->right = new Node(9);
    // root->right->left->left = new Node(10);
    // root->right->left->right = new Node(11);
    // root->right->right->left = new Node(12);
    // root->right->right->right = new Node(13);
    // boundary b;
    // vector<int> ans = b.boundaryOfBinaryTree(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl; // 1 2 3 5 6 10 11 12 13 9 7

    //! 987. Vertical Order Traversal of a Binary Tree
    // struct Node *root = new Node(3);
    // root->left = new Node(9);
    // root->right = new Node(20);
    // root->right->left = new Node(15);
    // root->right->right = new Node(7);
    // vector<vector<int>> ans = verticalTraversal(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //! 199. Binary Tree Right Side View
    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->left->right = new Node(5);
    // root->right = new Node(3);
    // root->right->right = new Node(4);
    // Right_Side_View r;
    // vector<int> ans = r.rightSideView(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    //! 101. Symmetric Tree
    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->left->left = new Node(3);
    // root->left->right = new Node(4);
    // root->right = new Node(2);
    // root->right->left = new Node(4);
    // root->right->right = new Node(3);
    // if(isSymmetric(root)){
    //     cout << "yes the tree is symmetric" << endl;
    // }else{
    //     cout << "no the tree is not symmetric" << endl;
    // }

    return 0;
}