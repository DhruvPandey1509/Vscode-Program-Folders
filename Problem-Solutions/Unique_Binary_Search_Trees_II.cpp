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
    vector<TreeNode *> construct(int st, int en)
    {
        vector<TreeNode *> trees;
        if (st > en)
        {
            trees.push_back(NULL);
            return trees;
        }

        for (int i = st; i <= en; i++)
        {
            vector<TreeNode *> leftSubtree = construct(st, i - 1);
            vector<TreeNode *> rightSubtree = construct(i + 1, en);

            for (int j = 0; j < leftSubtree.size(); j++)
            {
                TreeNode *left = leftSubtree[j];
                for (int k = 0; k < rightSubtree.size(); k++)
                {
                    TreeNode *right = rightSubtree[k];

                    TreeNode *node = new TreeNode(i);
                    node->left = left;
                    node->right = right;

                    trees.push_back(node);
                }
            }
        }

        return trees;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        int st = 1;
        return construct(st, n);
    }
};