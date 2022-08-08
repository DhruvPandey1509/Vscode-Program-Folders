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
    bool mirror(TreeNode *left, TreeNode *right)
    {
        if (!left and !right)
            return true;

        if (!left || !right)
            return false;

        if (left->val == right->val)
        {
            return mirror(left->left, right->right) and mirror(left->right, right->left);
        }

        return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        return mirror(root->left, root->right);
    }
};