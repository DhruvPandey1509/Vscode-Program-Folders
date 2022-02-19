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

bool isBST(Node* root, Node* minl = NULL, Node* maxl= NULL)
{
    if(root == NULL)
    {
        return true;
    }
    if(minl != NULL && root->data <= minl->data)
    {
        return false;
    }
    if(maxl != NULL && root->data >= maxl->data)
    {
        return false;
    }
    bool leftValid = isBST(root->left, minl, root);
    bool rightValid = isBST(root->right, root, maxl);

    return(leftValid & rightValid);
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    /*
        1
       / \
      2   3

    */

    if(isBST(root1, NULL, NULL))
    {
      cout<<"Valid BST"<<endl;
    }
    else
    {
        cout<<"Invalid BST"<<endl;
    }

    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(7);
    /*
        5
       / \ 
      3   7
    
    */
    if(isBST(root2, NULL, NULL))
    {
      cout<<"Valid BST"<<endl;
    }
    else
    {
        cout<<"Invalid BST"<<endl;
    }
    return 0; 
}