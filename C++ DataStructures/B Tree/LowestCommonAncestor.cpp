#include <iostream>
#include <vector>
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

bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }
    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2) // time complexity( O(n)) but complex to code as
{                                   // another func getpath is also required to be written
    vector<int> path1, path2;
    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }

    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }

    return path1[pc - 1];
}

Node *LCA2(Node *root, int n1, int n2) // time complexity( O(n) ) But better and easier to code
{                                      // use this more oftenly.
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftLCA = LCA2(root->left, n1, n2);
    Node *rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA && rightLCA) // both leftlca and rightlca are valid
    {                        // it means that one node exist in left subtree and another node exits
        return root;         // in right subtree.
    }

    if (leftLCA != NULL)
    {
        return leftLCA;
    }
    return rightLCA; // if leftLca == NULL and rightLca != NULL
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    /*
        1
       / \
      2   3
    */
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    /*
         1
       /    \
      2      3
    /  \    /  \
   4    5  6    7

    */
    int n1 = 7, n2 = 6;
    int lca = LCA(root, n1, n2);

    (lca == -1) ? cout << "LCA doesn't exist" << endl : cout << "Lca : " << lca << endl;
    Node *lca2 = LCA2(root, n1, n2);
    (lca2 == NULL) ? cout << "LCA doesn't exist" << endl : cout << "Lca : " << lca << endl;
    return 0;
}