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
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    /*
        1
       / \
      2   3
    */
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    flatten(root);
    inorder(root);
}