#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool checkCycle(vector<int> adj[], vector<int> &vis, vector<int> &pathVis, vector<int> &check, int node)
    {
        vis[node] = 1;
        check[node] = 0;
        pathVis[node] = 1;
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                if (checkCycle(adj, vis, pathVis, check, i))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVis[i])
            {
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        vector<int> check(V, 0);
        vector<int> safeNodes;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                checkCycle(adj, vis, pathVis, check, i);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *temp = curr->left;
                while (temp->right != NULL && temp->right != curr)
                {
                    temp = temp->right;
                }
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                else
                {
                    temp->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};