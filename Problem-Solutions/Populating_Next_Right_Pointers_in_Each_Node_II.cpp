#include "bits/stdc++.h"
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;
        if (root->left == NULL and root->right == NULL)
        {
            root->next = NULL;
            return root;
        }

        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < q.size() - 1; i++)
            {
                if (q.front() == NULL)
                    break;

                Node *node = q.front();
                q.pop();
                node->next = q.front();

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }
            if (q.front() == NULL)
            {
                q.pop();
                if (!q.empty())
                    q.push(NULL);
            }
        }

        return root;
    }
};