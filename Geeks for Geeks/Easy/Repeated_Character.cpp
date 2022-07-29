#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    char firstRep(string s)
    {
        unordered_map<char, int> m;
        pair<char, int> res('#', INT_MAX);

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (m.find(c) == m.end()) // first appearance
            {
                m[c] = i;
            }
            else
            {
                if (res.second > m[c])
                {
                    res.first = c;
                    res.second = m[c];
                }
            }
        }

        return res.first;
    }
};