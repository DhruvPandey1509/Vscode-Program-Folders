#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> v;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                v.push_back(i);
            }
        }

        vector<int> res;

        for (int i = 0; i < s.size(); i++)
        {
            int mn = INT_MAX;
            for (int j = 0; j < v.size(); j++)
            {
                mn = min(mn, abs(v[j] - i));
            }
            res.push_back(mn);
        }

        return res;
    }
};