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
    void preorder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;

        if (root->left == NULL and root->right == NULL)
            v.push_back(root->val);

        preorder(root->left, v);
        preorder(root->right, v);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leftTree, rightTree;

        preorder(root1, leftTree);
        preorder(root2, rightTree);

        return leftTree == rightTree;
    }
};