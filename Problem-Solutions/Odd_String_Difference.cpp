#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string oddString(vector<string> &words)
    {
        map<vector<int>, pair<string, int>> m;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            int n1 = word.size();
            vector<int> res;
            for (int j = 1; j < n1; j++)
            {
                int diff = word[j] - word[j - 1];
                res.push_back(diff);
            }

            if (m.find(res) != m.end())
            {
                m[res] = {word, -1};
            }
            else
            {
                m[res] = {word, 1};
            }
        }

        for (auto i : m)
        {
            if (i.second.second == 1)
                return i.second.first;
        }
        return "";
    }
};