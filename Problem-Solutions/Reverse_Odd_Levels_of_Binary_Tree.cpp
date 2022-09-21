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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (root == NULL)
            return root;

        queue<TreeNode *> q;
        q.push(root);
        vector<int> res;
        int level = 0;
        vector<int> v;

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (level % 2 != 0)
                {
                    node->val = res[n - 1 - i];
                }
                if (node->left != NULL)
                {
                    q.push(node->left);
                    v.push_back(node->left->val);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                    v.push_back(node->right->val);
                }
            }

            res = v;
            v.clear();
            level++;
        }

        return root;
    }
};
