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
    map<TreeNode *, int> m;
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        if (m.find(root) != m.end())
            return m[root];

        int left = height(root->left);
        int right = height(root->right);
        m[root] = max(left, right) + 1;
        return max(left, right) + 1;
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        int left = height(root->left);
        int right = height(root->right);

        if (left == right)
        {
            return root;
        }
        else if (left > right)
        {
            return subtreeWithAllDeepest(root->left);
        }
        else if (right > left)
        {
            return subtreeWithAllDeepest(root->right);
        }
        return NULL;
    }
};
