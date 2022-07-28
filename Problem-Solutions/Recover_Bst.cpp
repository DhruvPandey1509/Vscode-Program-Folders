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
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void calc(TreeNode *root, TreeNode **first, TreeNode **mid, TreeNode **last, TreeNode **prev)
    {
        if (root == NULL)
            return;

        calc(root->left, first, mid, last, prev);

        if (*prev and root->val < (*prev)->val)
        {
            if (!*first)
            {
                *first = *prev;
                *mid = root;
            }
            else
            {
                *last = root;
            }
        }

        *prev = root;
        calc(root->right, first, mid, last, prev);
    }

    void recoverTree(TreeNode *root)
    {
        TreeNode *first, *mid, *last, *prev;
        first = mid = last = prev = NULL;

        calc(root, &first, &mid, &last, &prev);

        if (first and last)
        {
            swap(&(first->val), &(last->val));
        }
        else if (first and mid)
        {
            swap(&(first->val), &(mid->val));
        }
    }
};