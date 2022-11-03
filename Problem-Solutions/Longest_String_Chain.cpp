#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    static bool cmp(string a, string b)
    {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string> &words)
    {

        unordered_map<string, int> m;
        sort(words.begin(), words.end(), cmp);

        int res = 0;
        for (auto word : words)
        {
            for (int i = 0; i < word.length(); i++)
            {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                m[word] = max(m[word], m[predecessor] + 1);
            }
            res = max(res, m[word]);
        }

        return res;
    }
};