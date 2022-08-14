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
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {

        int minDiff = INT_MAX;
        inorder(root);
        for (int i = 1; i < v.size(); i++)
        {
            minDiff = min(minDiff, abs(v[i] - v[i - 1]));
        }

        return minDiff;
    }
};