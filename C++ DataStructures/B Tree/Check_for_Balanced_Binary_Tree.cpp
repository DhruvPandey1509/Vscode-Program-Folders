#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.
    int height(Node *root)
    {
        if (root == NULL)
            return 0;

        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(Node *root)
    {
        if (root == NULL)
            return 1;

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(rh - lh) <= 1 and isBalanced(root->left) and isBalanced(root->right))
            return 1;

        return 0;
    }
};