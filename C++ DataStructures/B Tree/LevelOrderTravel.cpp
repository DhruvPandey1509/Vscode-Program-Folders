#include <iostream>
#include <queue>
using namespace std;

template<typename T>
class node
{
public:
    T data;
    node *left;
    node *right;
    
    node(T d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
template<class T>
node *buildTree()
{
    T d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main()
{
    node *root = buildTree();
    inorder(root);

    return 0;
}