#include "bits/stdc++.h"
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// A utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class Solution
{
public:
    // Function that constructs BST from its preorder traversal.
    Node *insert(Node *root, int val)
    {
        if (root == NULL)
        {
            root = newNode(val);
            return root;
        }

        if (root->data > val)
        {
            root->left = insert(root->left, val);
        }
        else if (root->data < val)
        {
            root->right = insert(root->right, val);
        }
    }
    Node *post_order(int pre[], int size)
    {
        Node *root = newNode(pre[0]);

        for (int i = 1; i < size; i++)
        {
            insert(root, pre[i]);
        }

        return root;
    }
};