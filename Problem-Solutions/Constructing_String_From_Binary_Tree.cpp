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
    string res = "";
    void preorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        // convert current value to string and add it to our result
        res += to_string(root->val);

        // if node is a leaf, no point in going ahead -> optimization
        if (root->left == NULL and root->right == NULL)
            return;

        // we will add '(' before calling left/right subtrees
        // and add ')' after the call

        // one point is, for left subtree, we will have to include the empty ()
        // as not including them will affect the one to one mapping
        res += "(";
        preorder(root->left);
        res += ")";

        // for right subtree, we will add only if there is some value in the subtree
        if (root->right != NULL)
        {
            res += "(";
            preorder(root->right);
            res += ")";
        }
    }
    string tree2str(TreeNode *root)
    {
        preorder(root);
        return res;
    }
};