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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {

        if (root == NULL)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node != NULL)
            {
                v.push_back(node->val);
                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            if (q.front() == NULL)
            {
                res.push_back(v);
                v = {};
                q.pop();
                q.push(NULL);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};