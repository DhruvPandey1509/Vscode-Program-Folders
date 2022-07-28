#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    Node *left;
    int val;
    Node *right;

    Node(int data)
    {
        left = NULL;
        val = data;
        right = NULL;
    }
};

void traverse(Node *root, vector<int> &res, int level)
{
    if (root == NULL)
        return;

    if (res.size() < level)
        res.push_back(root->val);

    traverse(root->left, res, level + 1);
    traverse(root->right, res, level + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    traverse(root, res, 1);
    return res;
}