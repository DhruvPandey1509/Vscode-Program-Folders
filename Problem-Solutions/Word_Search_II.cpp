#include "bits/stdc++.h"
using namespace std;

class Solution
{
    struct node
    { // TrieNode
        char c;
        int ends;
        string word;
        node *child[26];
    };
    struct node *getNode(char c)
    {
        node *newnode = new node;
        newnode->c = c;
        newnode->ends = 0;
        newnode->word = "";
        for (int i = 0; i < 26; i++)
        {
            newnode->child[i] = NULL;
        }
        return newnode;
    }
    node *root = getNode('/'); // root

    // Trie Insert
    void insert(string s)
    {
        node *curr = root;
        int idx, i = 0;
        while (s[i])
        {
            idx = s[i] - 'a';
            if (curr->child[idx] == NULL)
            {
                curr->child[idx] = getNode(s[i]);
            }
            curr = curr->child[idx];
            i += 1;
        }
        curr->ends += 1;
        curr->word = s;
    }

public:
    void solve(vector<vector<char>> &board, int i, int j, int r, int c, vector<string> &res, node *curr)
    {
        // Base case
        int idx = board[i][j] - 'a';
        if (board[i][j] == '%' || curr->child[idx] == NULL)
            return;

        curr = curr->child[idx];
        if (curr->ends > 0)
        {
            res.push_back(curr->word);
            curr->ends -= 1;
        }

        char ch = board[i][j];
        board[i][j] = '%'; // mark current node visited

        if (i > 0)
            solve(board, i - 1, j, r, c, res, curr);
        if (i < r - 1)
            solve(board, i + 1, j, r, c, res, curr);
        if (j > 0)
            solve(board, i, j - 1, r, c, res, curr);
        if (j < c - 1)
            solve(board, i, j + 1, r, c, res, curr);

        board[i][j] = ch; // Mark the current node as unvisited by restoring the value
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < words.size(); i++)
        {
            insert(words[i]);
        }

        vector<string> res;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                solve(board, i, j, r, c, res, root);
            }
        }

        return res;
    }
};