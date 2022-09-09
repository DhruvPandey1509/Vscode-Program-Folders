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
    int level = 0;
    int maxSum = INT_MIN;

    void levelOrderTraversal(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        int lvl = 1;
        int currSum = 0;

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node != NULL)
            {
                currSum += node->val;
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }

            else if (!q.empty())
            {
                if (currSum > maxSum)
                {
                    maxSum = currSum;
                    level = lvl;
                }
                lvl++;
                currSum = 0;
                q.push(NULL);
            }
        }

        if (currSum > maxSum)
        {
            level = lvl;
        }
    }
    int maxLevelSum(TreeNode *root)
    {
        levelOrderTraversal(root);
        return level;
    }
};
Maximum Level Sum of a Binary Tree