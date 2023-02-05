#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isVowel(char x)
    {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> pref(words.size() + 1);
        int i = 0;
        for (auto word : words)
        {
            pref[i + 1] = pref[i] + (isVowel(word[0]) and isVowel(word[word.size() - 1]));
            i++;
        }
        vector<int> res;
        for (auto q : queries)
        {
            res.push_back(pref[q[1] + 1] - pref[q[0]]);
        }
        return res;
    }
};

// Count Vowel Strings in Ranges