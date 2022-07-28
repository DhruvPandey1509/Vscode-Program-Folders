#include <iostream>
#include <stack>
using namespace std;
// Time Complexity = O(n)
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

void zigZagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> currlevel;
    stack<Node *> nextlevel;

    bool leftToRight = true;

    currlevel.push(root);

    while (!currlevel.empty())
    {
        Node *temp = currlevel.top();
        currlevel.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";

            if (leftToRight) // leftToRight is true
            {
                if (temp->left != NULL)
                {
                    nextlevel.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    nextlevel.push(temp->right);
                }
            }
            else // leftToRight is false
            {
                if (temp->right != NULL)
                {
                    nextlevel.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    nextlevel.push(temp->left);
                }
            }
        }

        if (currlevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currlevel, nextlevel);
        }
    }
}

int main()
{
    /*     12
          /  \
         9    15
        / \
       5   10
    */

    Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);

    zigZagTraversal(root);

    return 0;
}
