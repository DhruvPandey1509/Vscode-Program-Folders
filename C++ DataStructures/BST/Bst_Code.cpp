#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        left = right = NULL;
    }
};

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        // root->data = value;
        // return root;
        return new Node(value);
    }

    // rec case
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
bool search(Node *root, int value)
{
    if (root == NULL)
    {
        return false;
    }
    if (value == root->data)
    {
        return true;
    }
    if (value > root->data)
    {
        return search(root->right, value);
    }
    return search(root->left, value);
}

Node *inorderSuccessor(Node *root)
{
    if (root != NULL)
    {
        while (root->left && root)
        {
            root = root->left;
        }
        return root;
    }

    return NULL;
}

Node *remove(Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    else if (value < root->data)
    {
        root->left = remove(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = remove(root->right, value);
    }
    // when the current node matches with the key
    else
    {
        // 1.) No children
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            root = NULL;
            return root;
        }

        // 2.) single children
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
            return root;
        }

        // 3.) Two children
        Node *temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
}

int main()
{
    Node *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int x : arr)
    {
        root = insert(root, x);
    }
    inorder(root);
    cout << endl;
    cout << search(root, 12) << endl;
    cout << search(root, 10) << endl;
    cout << search(root, 4) << endl;

    remove(root, 6);
    inorder(root);
    return 0;
}