#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;

    Node(int val)
    {
        left = NULL;
        data = val;
        right = NULL;
    }
};

vector<Node *> constructTrees(int st, int en)
{
    vector<Node *> trees;
    if (st > en)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = st; i <= en; i++)
    {
        vector<Node *> leftSubtrees = constructTrees(st, i - 1);
        vector<Node *> rightSubtrees = constructTrees(i + 1, en);

        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            Node *left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                Node *right = rightSubtrees[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;

                trees.push_back(node);
            }
        }
    }

    return trees;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<Node *> totalTrees = constructTrees(1, 3);

    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << i + 1 << " : ";
        preorder(totalTrees[i]);
        cout << endl;
    }
    return 0;
}