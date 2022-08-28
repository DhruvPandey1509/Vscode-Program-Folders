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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return res;

        bool right_to_left = true;
        vector<int> v;
        queue<TreeNode *> p;
        p.push(root);
        p.push(NULL);

        res.push_back({root->val});

        while (!p.empty())
        {
            TreeNode *curr = p.front();
            p.pop();

            if (curr != NULL)
            {
                if (curr->left != NULL)
                {
                    p.push(curr->left);
                    v.push_back(curr->left->val);
                }

                if (curr->right != NULL)
                {
                    p.push(curr->right);
                    v.push_back(curr->right->val);
                }
            }
            if (curr == NULL)
            {
                if (p.empty())
                    break;

                if (right_to_left)
                    reverse(v.begin(), v.end());

                res.push_back(v);
                v.clear();

                p.push(NULL);
                right_to_left = !right_to_left;
            }
        }
        return res;
    }
};