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
    int count = 0;
    vector<int> helper(TreeNode *root, int d)
    {
        if (root == NULL)
            return {0};

        if (root->left == NULL and root->right == NULL)
            return {1};

        vector<int> left = helper(root->left, d);
        vector<int> right = helper(root->right, d);

        for (auto l : left)
        {
            for (auto r : right)
            {
                if (l > 0 and r > 0)
                {
                    if (l + r <= d)
                        count++;
                }
            }
        }

        vector<int> res;
        for (auto l : left)
        {
            if (l > 0 and l < d)
                res.push_back(l + 1);
        }
        for (auto r : right)
        {
            if (r > 0 and r < d)
            {
                res.push_back(r + 1);
            }
        }

        return res;
    }
    int countPairs(TreeNode *root, int distance)
    {
        vector<int> res = helper(root, distance);

        return count;
    }
};
