#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

};

int calcHeight(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);
    return max(leftHeight,rightHeight) +1;
}

int calcDiameter(Node* root) // O(n^2)
{                            //since calcHeight = O(n)
    if(root == NULL)         //and its is being called n times in calcDia
    {                       //:. n*n = n^2
        return 0;
    }

    int leftheight = calcHeight(root->left);
    int rightheight = calcHeight(root->right);

    int currDia = leftheight + rightheight + 1;

    int leftdia = calcDiameter(root->left);
    int rightDia = calcDiameter(root->right);

    return max(currDia, max(leftdia,rightDia));
}

int calcDia(Node* root, int *height) // optimised function for calculating diameter
{                                    //O(n)
    if(root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0 , rh = 0;
    int leftDia = calcDia(root->left, &lh);
    int rightDia = calcDia(root->right, &rh);

    int currDia = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDia, max(leftDia, rightDia));

}
int main()
{
    struct Node* root = new Node(1);
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

    cout<<calcHeight(root)<<endl;
    cout<<calcDiameter(root)<<endl; 
    int height = 0;
    cout<<calcDia(root,&height)<<endl;

    return 0;
}