#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    /** This function replace replaces each char with the index where it appers for the             first time.
        abb --> 011
        abc --> 012
        deq --> 012
        mee --> 011
        dkd --> 010
        ccc --> 000
    **/
    string replace(unordered_map<char, int> &idx, string word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (idx.find(word[i]) == idx.end())
                idx[word[i]] = i;
            word[i] = idx[word[i]] + '0';
        }
        return word;
    }
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> res;
        unordered_map<char, int> idx;
        pattern = replace(idx, pattern);

        for (string word : words)
        {
            idx = {}; // emptying map;
            string temp = replace(idx, word);
            if (temp == pattern)
                res.push_back(word);
        }
        return res;
    }
};
