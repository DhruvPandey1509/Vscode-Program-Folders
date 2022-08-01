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

void getVerticalOrder(Node *root, int hDis, map<int, vector<int>> &m)
{
    if (root == NULL)
        return;

    m[hDis].push_back(root->val);
    getVerticalOrder(root->left, hDis - 1, m);
    getVerticalOrder(root->right, hDis + 1, m);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(11);

    root->right = new Node(4);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    map<int, vector<int>> m; // key = hDis  value = all the elements at that level
    int hDis = 0;            // horizontal distance
    getVerticalOrder(root, hDis, m);
    for (auto i : m)
    {
        cout << i.first << " : ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}