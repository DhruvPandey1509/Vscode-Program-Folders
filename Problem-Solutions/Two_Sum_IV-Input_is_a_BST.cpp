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
    unordered_map<int, int> m;
    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        traverse(root->left);
        m[root->val]++;
        traverse(root->right);
    }
    bool findTarget(TreeNode *root, int k)
    {
        traverse(root);
        for (auto i : m)
        {
            m[i.first]--;
            if (m.find(k - i.first) != m.end() and m[k - i.first] > 0)
                return true;
        }

        return false;
    }
};