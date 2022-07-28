#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isIdentical(Node *root1, Node *root2)
{
    //structurally identical
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    //structurally non-identical
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    else
    {
        bool cond1 = root1->data == root2->data;              //comparing  curr root's data
        bool cond2 = isIdentical(root1->left, root2->left);   //checking for root's left subtree
        bool cond3 = isIdentical(root1->right, root2->right); //checking for roots right subtree

        //if all the consitions are true.
        if (cond1 && cond2 && cond3)
        {
            return true;
        } 

        return false;
    }
}

int main()
{
    /*
          1
           \
            3
           /  \
          2    5
    */

    Node *root = new Node(1);
    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(5);

    /*
          1
           \
            3
           /  \
          2    5
    */
    Node *root1 = new Node(1);
    root1->right = new Node(3);
    root1->right->left = new Node(2);
    root1->right->right = new Node(5);

    bool cond = isIdentical(root, root1);
    (cond == true) ? cout << "True" << endl : cout << "False" << endl;

    /*
          1
           \
            3
           /  \
          2    5
    */
    Node *root2 = new Node(1);
    root2->right = new Node(3);
    root2->right->left = new Node(2);
    root2->right->right = new Node(5);

    /*
          1
           \
            3
           /  \
          2    8
    */
    Node *root3 = new Node(1);
    root3->right = new Node(3);
    root3->right->left = new Node(2);
    root3->right->right = new Node(8);

    bool cond1 = isIdentical(root2, root3);
    (cond1 == true) ? cout << "True" << endl : cout << "False" << endl;

    return 0;
}