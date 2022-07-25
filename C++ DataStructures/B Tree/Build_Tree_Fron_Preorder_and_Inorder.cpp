#include "bits/stdc++.h"
using namespace std;

struct Node
{
    struct Node *left;
    int val;
    struct Node *right;

    Node(int data)
    {
        left = NULL;
        val = data;
        right = NULL;
    }
};
int search(int inorder[], int st, int en, int curr)
{
    for (int i = st; i <= en; i++)
    {
        if (inorder[i] == curr)
            return i;
    }

    return -1;
}
Node *buildTree(int preorder[], int inorder[], int st, int en)
{
    if (st > en)
        return NULL;

    static int idx = 0;
    int curr = preorder[idx];
    idx++;

    Node *node = new Node(curr);

    if (st == en)
        return node;
    int pos = search(inorder, st, en, curr);
    node->left = buildTree(preorder, inorder, st, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, en);
}
void preorderPrint(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}
int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node *root = buildTree(preorder, inorder, 0, 4);

    preorderPrint(root);
}