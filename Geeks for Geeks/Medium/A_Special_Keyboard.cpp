#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findTime(string s1, string s2)
    {
        unordered_map<char, int> m;

        for (int i = 0; i < 26; i++)
        {
            m[s1[i]] = i;
        }

        int currIdx = 0;
        int idx, res = 0;

        for (char c : s2)
        {
            idx = m[c];
            res += abs(idx - currIdx);
            currIdx = idx;
        }

        return res;
    }
};