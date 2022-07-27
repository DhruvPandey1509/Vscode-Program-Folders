#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;

    Node(int val)
    {
        left = NULL;
        data = val;
        right = NULL;
    }
};

class Solution
{
public:
    bool solve(Node *root, int mini, int maxi)
    {
        if (root == NULL)
            return true;

        if (root->data > mini and root->data < maxi)
        {
            return solve(root->left, mini, root->data) and
                   solve(root->right, root->data, maxi);
        }

        else
            return false;
    }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root)
    {
        int mini = INT_MIN;
        int maxi = INT_MAX;

        return solve(root, mini, maxi);
    }
};