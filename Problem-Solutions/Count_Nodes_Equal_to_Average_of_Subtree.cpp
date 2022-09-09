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
    pair<int, int> dfs(TreeNode *root, int &res)
    {
        if (root == NULL)
            return {0, 0};

        auto left_subtree = dfs(root->left, res);
        auto right_subtree = dfs(root->right, res);

        int sum = root->val + left_subtree.first + right_subtree.first;
        int count = 1 + left_subtree.second + right_subtree.second; // number of nodes in subtree for parent node

        if (sum / count == root->val)
            res++;

        return {sum, count};
    }
    int averageOfSubtree(TreeNode *root)
    {
        int res = 0;
        dfs(root, res);
        return res;
    }
};

// Bfs and level order Traversal
class Solution1
{
public:
    int res = 0;
    void bfs(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root == NULL)
            return;

        q.push(root);
        int sum = 0;
        int count = 0;
        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                count++;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        if (sum / count == root->val)
            res++;
    }
    int averageOfSubtree(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root == NULL)
            return res;

        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                bfs(node);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return res;
    }
};