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
    int steps = 0;
    int solve(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int l = solve(root->left);
        steps += abs(l);
        int r = solve(root->right);
        steps += abs(r);

        root->val += l + r;
        return root->val - 1;
    }
    int distributeCoins(TreeNode *root)
    {
        solve(root);
        return steps;
    }
};
