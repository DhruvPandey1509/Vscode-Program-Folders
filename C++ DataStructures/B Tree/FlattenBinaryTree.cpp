#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);

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
    {
        return;
    }
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

int main()
{
    struct Node *root = new Node(1);
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
    /*
         1
       /    \
      2      3
    /  \    /  \
   4    5  6    7

    */
    inorder(root);
    cout << endl;
    flatten(root);
    /*
        1
         \ 
          2
           \
            3
             \
              4
               \
                5
                 \
                  6
                   \
                    7
    */
    inorder(root);
    cout << endl;

    Node *root1 = new Node(4);
    root1->left = new Node(9);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    root1->right = new Node(5);
    root1->right->right = new Node(6);
    /*
        4
      /   \
     9     5
    / \     \
   1   3     6
      */

    inorder(root1);
    cout << endl;
    flatten(root1);
    /*
        4
         \
          9
           \
            1
             \
              3
               \
                5
                 \
                  6 
    */
    inorder(root1);
    cout << endl;

    return 0;
}