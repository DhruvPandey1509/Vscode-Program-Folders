#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        unordered_map<char, int> m;
        int n = travel.size();
        vector<int> prefix(n);
        prefix[0] = travel[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + travel[i];
        }
        int size = garbage.size();
        vector<int> lastIdx(3, -1); // 0 = 'G', 1 = 'P', 2 = 'M';
        for (int i = 0; i < size; i++)
        {
            for (char c : garbage[i])
            {
                m[c]++;
                if (c == 'G')
                    lastIdx[0] = i;
                else if (c == 'P')
                    lastIdx[1] = i;
                else if (c == 'M')
                    lastIdx[2] = i;
            }
        }
        int res = m['G'];
        res += m['P'];
        res += m['M'];
        if (lastIdx[0] > 0)
            res += prefix[lastIdx[0] - 1];
        if (lastIdx[1] > 0)
            res += prefix[lastIdx[1] - 1];
        if (lastIdx[2] > 0)
            res += prefix[lastIdx[2] - 1];
        return res;
    }
};