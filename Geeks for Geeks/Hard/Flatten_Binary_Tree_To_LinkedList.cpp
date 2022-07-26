#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    Node *left;
    int key;
    Node *right;
};

class Solution
{
public:
    void flatten(Node *root)
    {
        if (root == NULL || (root->left == NULL and root->right == NULL))
        {
            return;
        }

        if (root->left != NULL)
        {
            Node *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            Node *t = root->right;
            while (t->right != NULL)
            {
                t = t->right;
            }
            t->right = temp;
        }
        flatten(root->right);
    }
};