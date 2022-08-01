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
    // store format {col1 :{{row1, value1}}, ...}

    void traverse(TreeNode *root, int col, int row, map<int, multiset<pair<int, int>>> &m)
    {
        if (root)
        {
            m[col].insert({row, root->val});
            traverse(root->left, col - 1, row + 1, m);
            traverse(root->right, col + 1, row + 1, m);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, multiset<pair<int, int>>> m;
        traverse(root, 0, 0, m);
        vector<vector<int>> res;

        for (auto i : m)
        {

            vector<int> v;
            for (auto j : i.second)
                v.push_back(j.second);
            res.push_back(v);
        }
        return res;
    }
};