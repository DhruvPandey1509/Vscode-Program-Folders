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
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *bst(int arr[], int st, int en)
{
    if (st > en)
        return NULL;

    int mid = st + (en - st) / 2;
    Node *root = new Node(arr[mid]);

    root->left = bst(arr, st, mid - 1);
    root->right = bst(arr, mid + 1, en);

    return root;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int st = 0;
    int en = sizeof(arr) / sizeof(arr[0]) - 1;

    Node *root = bst(arr, st, en);
    inorder(root);

    return 0;
}