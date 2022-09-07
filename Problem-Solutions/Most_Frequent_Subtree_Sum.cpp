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
    int maxi = -1;
    map<int, int> m;

    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int total = dfs(root->left) + dfs(root->right) + root->val;
        m[total]++;

        // maintaining the maximum freq
        maxi = max(maxi, m[total]);
        return total;
    }

    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        dfs(root);
        vector<int> res;
        for (auto i : m)
        {
            if (i.second == maxi) // if the current sum in subtree has freq equal to the maximum freq we calculated push it
            {
                res.push_back(i.first);
            }
        }
        return res;
    }
};
