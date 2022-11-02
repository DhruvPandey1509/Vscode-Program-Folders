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
    int traverse(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        if (root->left == NULL || root->left->val != root->val)
            left = 0;
        if (root->right == NULL || root->right->val != root->val)
            right = 0;
        res = max(res, left + right);
        return max(left, right) + 1;
    }
    int longestUnivaluePath(TreeNode *root)
    {
        int x = traverse(root);
        return res;
    }
};
