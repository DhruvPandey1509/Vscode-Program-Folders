#include "bits/stdc++.h"
using namespace std;

// class Trie
// {
// private:
//     struct Node
//     {
//         Node *child[26] = {NULL};
//         bool isWord = false;
//     };
//     Node *root;

// public:
//     Trie()
//     {
//         root = new Node();
//     }

//     void insert(string word)
//     {
//         Node *temp = root;
//         for (auto c : word)
//         {
//             if (!temp->child[c - 'a'])
//             {
//                 temp->child[c - 'a'] = new Node();
//             }
//             temp = temp->child[c - 'a'];
//         }
//         temp->isWord = true;
//     }

//     bool search(string word)
//     {
//         Node *temp = root;
//         for (auto c : word)
//         {
//             if (!temp->child[c - 'a'])
//                 return false;
//             temp = temp->child[c - 'a'];
//         }
//         return temp->isWord;
//     }

//     bool startsWith(string prefix)
//     {
//         Node *temp = root;
//         for (auto c : prefix)
//         {
//             if (!temp->child[c - 'a'])
//                 return false;
//             temp = temp->child[c - 'a'];
//         }
//         return true;
//     }
// };
struct Node
{
    Node *child[26] = {NULL};
    bool isWord = false;
};

void insert(Node *root, string word)
{
    Node *temp = root;
    for (auto c : word)
    {
        if (!temp->child[c - 'a'])
        {
            temp->child[c - 'a'] = new Node();
        }
        temp = temp->child[c - 'a'];
    }
    temp->isWord = true;
}

bool search(Node *root, string word)
{
    Node *temp = root;
    for (auto c : word)
    {
        if (!temp->child[c - 'a'])
            return false;
        temp = temp->child[c - 'a'];
    }
    return temp->isWord;
}

bool startsWith(Node *root, string prefix)
{
    Node *temp = root;
    for (auto c : prefix)
    {
        if (!temp->child[c - 'a'])
            return false;
        temp = temp->child[c - 'a'];
    }
    return true;
}
int main()
{
    Node *t = new Node();
    insert(t, "Dhruv");
    // insert(t, "Garvit");
    // insert(t, "Diva");
    cout << search(t, "Dhruv") << endl;
    return 0;
}