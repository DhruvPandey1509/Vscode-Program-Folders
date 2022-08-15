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
    bool isPresent(vector<pair<int, int>> v, int x, int y)
    {
        int xParent;
        int yParent;
        bool isX = false;
        bool isY = false;
        for (auto i : v)
        {
            if (i.first == x)
            {
                isX = true;
                xParent = i.second;
            }
            if (i.first == y)
            {
                isY = true;
                yParent = i.second;
            }
        }

        if (isX and isY)
        {
            if (xParent != yParent)
                return true;
        }
        return false;
    }

    bool isCousins(TreeNode *root, int x, int y)
    {

        if (root == NULL)
            return false;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        vector<pair<int, int>> v; // first == value  second = parent

        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

            if (currNode != NULL)
            {
                if (currNode->left != NULL)
                {
                    q.push(currNode->left);
                    v.push_back({currNode->left->val, currNode->val});
                }
                if (currNode->right != NULL)
                {
                    q.push(currNode->right);
                    v.push_back({currNode->right->val, currNode->val});
                }
            }

            if (q.front() == NULL)
            {
                q.pop();
                if (q.empty())
                    return false;

                if (isPresent(v, x, y))
                    return true;

                v.clear();
                q.push(NULL);
            }
        }
        return false;
    }
};