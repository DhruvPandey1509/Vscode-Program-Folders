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
    priority_queue<int, vector<int>, greater<int>> p;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        p.push(root->val);
        inorder(root->right);
    }
    int findSecondMinimumValue(TreeNode *root)
    {

        if (root == NULL)
            return -1;
        inorder(root);

        int res = -1;
        int x = p.top();
        p.pop();

        while (!p.empty())
        {
            if (p.top() != x)
            {
                res = p.top();
                break;
            }

            x = p.top();
            p.pop();
        }

        return res;
    }
};