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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;

        res.push_back(root->val);

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        vector<int> v;
        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

            if (currNode != NULL)
            {
                if (currNode->left != NULL)
                {
                    q.push(currNode->left);
                    v.push_back(currNode->left->val);
                }
                if (currNode->right != NULL)
                {
                    q.push(currNode->right);
                    v.push_back(currNode->right->val);
                }
            }
            if (q.front() == NULL)
            {
                q.pop();
                if (q.empty())
                    break;

                res.push_back(*max_element(v.begin(), v.end()));
                v.clear();

                q.push(NULL);
            }
        }

        return res;
    }
};