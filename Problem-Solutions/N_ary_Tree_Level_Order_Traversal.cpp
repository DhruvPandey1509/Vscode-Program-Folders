#include "bits/stdc++.h"
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {

        if (root == NULL)
            return {};

        vector<vector<int>> res;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> currlvl;
            for (int i = 0; i < n; i++)
            {
                Node *node = q.front();
                q.pop();
                currlvl.push_back(node->val);
                for (auto i : node->children)
                    q.push(i);
            }
            res.push_back(currlvl);
        }
        return res;
    }
};
// N-ary Tree Level Order Traversal