#include "bits/stdc++.h"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == NULL)
            return NULL;

        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode *leftLca = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightLca = lowestCommonAncestor(root->right, p, q);

        if (leftLca and rightLca)
            return root;

        if (!leftLca and !rightLca)
            return NULL;

        if (leftLca != NULL)
            return leftLca;
        return rightLca;
    }
};