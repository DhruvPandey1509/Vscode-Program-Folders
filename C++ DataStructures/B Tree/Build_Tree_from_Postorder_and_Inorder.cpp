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

void inorderPrint(Node *root)
{
    if (root == NULL)
        return;

    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int search(int inorder[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == value)
        {
            return i;
        }
    }
    return -1;
}
Node *buildTree(int postorder[], int inorder[], int st, int en)
{
    if (st > en)
    {
        return NULL;
    }

    static int idx = en;
    int value = postorder[idx];
    idx--;
    Node *curr = new Node(value);

    if (st == en)
    {
        return curr;
    }
    int pos = search(inorder, st, en, value);
    curr->right = buildTree(postorder, inorder, pos + 1, en);
    curr->left = buildTree(postorder, inorder, st, pos - 1);

    return curr;
}

int main()
{
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *root = buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}
