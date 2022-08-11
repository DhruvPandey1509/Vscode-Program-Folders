#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {

        unordered_map<char, pair<int, int>> m;

        for (int i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) == m.end())
            {
                m[s[i]].first = i;
            }
            m[s[i]].second++;
        }

        char ch;
        int idx = INT_MAX;
        for (auto i : m)
        {
            if (i.second.second == 1)
            {
                if (i.second.first < idx)
                {
                    ch = i.first;
                    idx = i.second.first;
                }
            }
        }

        if (idx == INT_MAX)
            return -1;
        return idx;
    }
};