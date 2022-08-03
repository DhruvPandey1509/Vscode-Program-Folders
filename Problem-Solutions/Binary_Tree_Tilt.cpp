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
    int getTiltSum(TreeNode *root, int &tiltSum)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL and root->right == NULL)
        {
            tiltSum += 0;
            return root->val;
        }

        int left = getTiltSum(root->left, tiltSum);
        int right = getTiltSum(root->right, tiltSum);

        tiltSum += abs(right - left);

        return root->val + left + right;
    }
    int findTilt(TreeNode *root)
    {
        int tiltSum = 0;
        getTiltSum(root, tiltSum);

        return tiltSum;
    }
};