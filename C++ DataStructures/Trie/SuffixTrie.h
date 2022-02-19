#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

class Node
{
    public:
    char data; 
    bool isTerminal;
    unordered_map<char, Node *> m; //key is cahracter ,   Node * (i.e Adderess)is value
    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};
 
class SuffixTrie
{ 
    Node *root;
    public:
    SuffixTrie()
    {
        root = new Node('\0');
    }

    // Insertion
    void insertHelper(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0) //unordered_map containers do not allow for duplicate keys, this means that
            {//the function actually returns 1 if an element with that key exists in the container, and zero otherwise.

                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
 
    // Searching
    bool search(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    void insert(string word)
    {
        // pick all the substring from (i, eos)  and insertHelper
        for(int i = 0 ; word[i] != '\0'; i++)
        {
            insertHelper(word.substr(i));
        }
    }
};