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

Node* insert(Node* root, int val)
{
    if(root == NULL)
    {
        return new Node(val);
    } 
    if(val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}
void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* search(Node* root, int val)
{
    if(root == NULL)
    {
        cout<<"Doesn't exist"<<endl;
        return root;
    }
    if(val == root->data)
    {
        cout<<"Exist"<<endl;
    }
    if(val < root->data)
    {
       search(root->left, val);
    }
    else if(val > root->data)
    {
        search(root->right, val);
    }

    return root;
}

Node* inorderSucc(Node* root)
{
    Node* curr = root;
    while(curr && curr->left != NULL)
    {
       curr = curr->left;
    }

    return curr;
}

Node* deleteInBST(Node* root , int val)
{
    if(val < root->data)
    {
        root->left = deleteInBST(root->left, val);
    }
    else if(val > root->data)
    {
        root->right = deleteInBST(root->right, val);
    }
    else
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        //case3
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }

    return root;
}

int main()
{
    Node* root = NULL;
    root = insert(root, 0);
    insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,6);
    inorder(root);
    cout<<endl;
    search(root,7);
    search(root,2);

    deleteInBST(root,2);
    inorder(root);
    return 0;
}
