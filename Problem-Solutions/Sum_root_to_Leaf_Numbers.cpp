#include "bits/stdc++.h"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int res = 0;
    void sum(TreeNode *root, int value)
    {
        value = value * 10 + root->val;
        if (root->left == NULL and root->right == NULL)
            res += value;

        if (root->right != NULL)
            sum(root->right, value);

        if (root->left != NULL)
            sum(root->left, value);

        return;
    }
    int sumNumbers(TreeNode *root)
    {
        sum(root, 0);
        return res;
    }
};