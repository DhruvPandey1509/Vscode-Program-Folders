#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;

    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};
class Trie
{

public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
};

void searchHelper(Trie t, string document, int i, unordered_map<string, bool> &m)
{
    Node *temp = t.root;
    for (int j = i; j < document.length(); j++)
    {
        char ch = document[j];
        if (temp->m.count(ch) == 0)
        // if (temp->m.count(ch) == 0)
        {
            return;
        }
        temp = temp->m[ch];
        if (temp->isTerminal)
        {
            string out = document.substr(i, j - i + 1);
            m[out] = true;
        }
    }
    return;
}

void documentSearch(string document, vector<string> words)
{
    // 1.) create trie of words
    Trie t;
    for (auto w : words)
    {
        t.insert(w);
    }
    // 2.) Searching (Helper Function)    
    unordered_map<string, bool> m;
    for (int i = 0; i < document.length(); i++)
    {
        searchHelper(t, document, i, m);
    }
    // 3. You can check which words are marked as true inside hashmap
    for (auto w : words)
    {
        if (m[w])
        {
            cout << w << " : True" << endl;
        }
        else
        {
            cout << w << " : False" << endl;
        }
    }
}
int main()
{
    string document = "catsandog"; 
    vector<string> words = {"cats", "dog", "sand", "and", "cat"};
    documentSearch(document, words);
    return 0;
}