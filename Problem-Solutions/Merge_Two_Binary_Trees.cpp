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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1)
            return root2;
        if (!root2)
            return root1;

        root1->val += root2->val;

        if (root1->left == NULL)
            root1->left = root2->left;
        else
            mergeTrees(root1->left, root2->left);

        if (root1->right == NULL)
            root1->right = root2->right;
        else
            mergeTrees(root1->right, root2->right);

        return root1;
    }
};