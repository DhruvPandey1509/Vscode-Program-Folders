#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    int maxPathSum(Node *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int left = maxPathSum(root->left, ans);
        int right = maxPathSum(root->right, ans);

        int nodeMax = max(root->data + max(0, left + right), root->data + max(left, right));
        ans = max(ans, nodeMax);
        int single_path_sum = max(root->data, root->data + max(left, right));
        return single_path_sum;
    }
    int findMaxSum(Node *root)
    {
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
};