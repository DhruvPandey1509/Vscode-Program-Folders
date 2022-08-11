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
    vector<vector<int>> res;

    void traverse(TreeNode *root, vector<int> &v, int targetSum)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL and root->right == NULL and targetSum == root->val)
        {
            v.push_back(root->val);
            res.push_back(v);
            v.pop_back();
            return;
        }

        targetSum = targetSum - root->val;
        v.push_back(root->val);
        traverse(root->left, v, targetSum);
        traverse(root->right, v, targetSum);
        v.pop_back();

        return;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> v;
        traverse(root, v, targetSum);

        return res;
    }
};