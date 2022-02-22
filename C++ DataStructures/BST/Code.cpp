#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}
int diameter(Node *root) //O(n^2)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int currDia = leftHeight + rightHeight + 1;

    int lDia = diameter(root->left);
    int rDia = diameter(root->right);

    return max(currDia, max(lDia, rDia));
}
int dia(Node *root, int *height) // optimised diameter calculating function O(n)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ld = dia(root->left, lh);
    int rd = dia(root->right, rh);

    int currD = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return, ax(currD, max(ld, rd));
}
int main()
{
    Node *root = NULL;
    root = insert(root, 0);
    insert(root, 6);
    insert(root, 2);
    insert(root, 5);
    insert(root, 12);
    insert(root, 1);
    insert(root, 3);
    insert(root, 8);
    insert(root, 11);
    insert(root, 7);
    insert(root, 4);
    inorder(root);

    cout << height(root) << endl;
    return 0;
}