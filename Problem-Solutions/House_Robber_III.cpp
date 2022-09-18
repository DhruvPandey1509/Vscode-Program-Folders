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
    unordered_map<TreeNode *, int> m;
    int rob(TreeNode *root)
    {

        if (m.find(root) != m.end())
            return m[root];
        if (!root)
            return 0;
        int with_root = root->val;
        if (root->left != NULL)
            with_root += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            with_root += rob(root->right->left) + rob(root->right->right);

        int without_root = rob(root->left) + rob(root->right);
        return m[root] = max(with_root, without_root);
    }
};

class Solution1 {
public:
    int sum = 0;
    int rob(TreeNode* root) {
        if(root == NULL)
        {
            sum = 0;
            return 0;
        }
        
        int l = rob(root->left);
        int preSum = sum;
        int r = rob(root->right);
        
        preSum += sum;
        sum = l+r;
        return max(preSum + root->val, sum);
    }
};