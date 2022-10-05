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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (root == NULL)
            return root;
        queue<TreeNode *> q;
        int currDepth = 1;
        
        if (depth == 1)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }

        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (currDepth == depth - 1)
                {
                    TreeNode *leftRoot = node->left;
                    TreeNode *rightRoot = node->right;
                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);
                    node->left->left = leftRoot;
                    node->right->right = rightRoot;
                }
                else
                {
                    if (node->left != NULL)
                        q.push(node->left);
                    if (node->right != NULL)
                        q.push(node->right);
                }
            }
            if (currDepth == depth - 1)
                break;
            currDepth++;
        }

        return root;
    }
};