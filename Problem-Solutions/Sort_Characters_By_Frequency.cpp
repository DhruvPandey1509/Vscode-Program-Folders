#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(pair<char, int> a, pair<char, int> b)
    {
        return a.second > b.second;
    }
    string frequencySort(string s)
    {
        unordered_map<char, int> m;

        for (char c : s)
        {
            m[c]++;
        }

        vector<pair<char, int>> v;

        for (auto i : m)
        {
            v.push_back({i.first, i.second});
        }

        sort(v.begin(), v.end(), cmp);
        string res = "";

        for (auto i : v)
        {
            while (i.second--)
            {
                res += i.first;
            }
        }

        return res;
    }
};