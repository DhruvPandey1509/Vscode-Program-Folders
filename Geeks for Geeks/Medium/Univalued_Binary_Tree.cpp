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
    int x = -1;
    bool isUnivalTree(TreeNode *root)
    {
        if (x == -1)
            x = root->val;

        if (root == NULL)
            return true;

        if (root->val != x)
            return false;

        return isUnivalTree(root->left) and isUnivalTree(root->right);
    }
};