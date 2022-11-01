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
    void solve(TreeNode *root, int p)
    {
        if (root == NULL)
            return;

        int sum = p * 2 + root->val;
        if (root->left == NULL and root->right == NULL)
        {
            res += sum;
            return;
        }

        solve(root->left, sum);
        solve(root->right, sum);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        solve(root, 0);
        return res;
    }
};
