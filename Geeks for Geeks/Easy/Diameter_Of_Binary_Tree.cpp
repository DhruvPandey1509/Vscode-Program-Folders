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
    // Function to return the diameter of a Binary Tree.
    int height(Node *root)
    {
        if (root == NULL)
            return 0;

        //      returning max of left height, rightheight     +1 = including rootnode
        return max(height(root->left), height(root->right)) + 1;
    }
    int diameter(Node *root)
    {
        if (root == NULL)
            return 0;
        // currDia = leftHeight + rightHeight + rootnode
        int currDia = height(root->left) + height(root->right) + 1;

        int leftDia = diameter(root->left);
        int rightDia = diameter(root->right);

        return max(currDia, max(leftDia, rightDia));
    }
};