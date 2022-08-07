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
    void countGoodNodes(TreeNode *root, int prevData, int &count)
    {
        if (root == NULL)
            return;

        if (root->val >= prevData)
        {
            count++;
            prevData = root->val;
        }

        countGoodNodes(root->left, prevData, count);
        countGoodNodes(root->right, prevData, count);
    }
    int goodNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL and root->right == NULL)
            return 1;
        int count = 1;

        if (root->left != NULL)
        {
            countGoodNodes(root->left, root->val, count);
        }

        if (root->right != NULL)
        {
            countGoodNodes(root->right, root->val, count);
        }

        return count;
    }
};