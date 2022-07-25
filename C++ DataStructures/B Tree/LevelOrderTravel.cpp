#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;

    Node(int data)
    {
        left = NULL;
        val = data;
        right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int count = 0;
    cout << "Level " << count << " : ";
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            cout << node->val << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            cout << endl;
            count++;
            cout << "Level " << count << " : ";
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    levelOrderTraversal(root);

    return 0;
}