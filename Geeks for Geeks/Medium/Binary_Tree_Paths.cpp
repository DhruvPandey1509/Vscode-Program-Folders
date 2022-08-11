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
    vector<string> res;
    void traverse(TreeNode *root, string s)
    {
        if (root == NULL)
            return;
        s += to_string(root->val);

        if (root->left != NULL || root->right != NULL)
        {
            s += "->";
        }

        if (root->left == NULL and root->right == NULL)
        {
            res.push_back(s);
            return;
        }

        traverse(root->left, s);
        traverse(root->right, s);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        traverse(root, "");

        return res;
    }
};