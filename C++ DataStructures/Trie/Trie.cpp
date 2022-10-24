#include "bits/stdc++.h"
using namespace std;
struct Node
{
    Node *links[26];
    bool isTerminal = false;
    
    bool containsKey(char ch)
    {
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch-'a'];
    }
};

class Trie
{
private : 
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    /*Insert a word into the trie*/
    void insert(string word)
    {
        Node *node = root;
        for(int i = 0 ; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            //moves ti the reference trie;
            node->get(word[i]);
        }
    }
    /** Returns if the word is in the Trie*/
    bool search(string word)
    {
    }

    /** Returns if their is any word in the trie that start with */
};