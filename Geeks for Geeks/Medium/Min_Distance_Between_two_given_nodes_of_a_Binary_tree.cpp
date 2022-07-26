#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    Node *lca(Node *root, int a, int b)
    {
        if (root == NULL)
            return NULL;

        if (root->data == a || root->data == b)
            return root;

        Node *leftLca = lca(root->left, a, b);
        Node *rightLca = lca(root->right, a, b);

        if (leftLca and rightLca)
            return root;
        if (!leftLca and !rightLca)
            return NULL;
        if (leftLca != NULL)
            return leftLca;

        return rightLca;
    }
    int distance(Node *root, int n, int dis)
    {
        if (root == NULL)
            return -1;

        if (root->data == n)
            return dis;

        int leftDis = distance(root->left, n, dis + 1);

        if (leftDis != -1)
            return leftDis;

        return distance(root->right, n, dis + 1);
    }

    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node *root, int a, int b)
    {

        Node *node = lca(root, a, b);
        int d1 = distance(node, a, 0);
        int d2 = distance(node, b, 0);

        return d1 + d2;
    }
};