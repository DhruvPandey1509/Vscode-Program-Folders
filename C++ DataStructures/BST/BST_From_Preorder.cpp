#include"bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* constructBST(int preorder[], int *preorderIdx, int key, int minl, int maxl,int n)
{
    Node* root = NULL;
    if(key > minl && key < maxl)
    {
        if(*preorderIdx > n)
        {
            return NULL;
        }
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if(*preorderIdx < n)
        {
              root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], minl, key, n);
        }
        if(*preorderIdx < n)
        {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, maxl, n);
        }
    }


    return root;
}

void printPreorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
    
}

int main()
{
    /*
          10
         /  \
        2    13
       /     /
      1     11

    */
    int preorder[] = {10,2,1,13,11};
    int n = sizeof(preorder)/sizeof(preorder[0]);
    int preorderIdx = 0;
    Node* root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    printPreorder(root);

    return 0;
}