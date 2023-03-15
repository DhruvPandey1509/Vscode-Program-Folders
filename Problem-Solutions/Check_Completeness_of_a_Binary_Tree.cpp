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
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr == NULL)
                {
                    flag = true;
                    continue;
                }
                else
                {
                    if (flag == true)
                        return false;
                    if (curr->left)
                        q.push(curr->left);
                    else
                        q.push(NULL);

                    if (curr->right)
                        q.push(curr->right);
                    else
                        (q.push(NULL));
                }
            }
        }

        return true;
    }
};