#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<char, int> m;
    static bool comp(pair<char, int> a, pair<char, int> b)
    {
        return a.second > b.second;
    }
    string frequencySort(string s)
    {
        for (char c : s)
        {
            m[c]++;
        }
        vector<pair<char, int>> v;
        for (auto i : m)
        {
            v.push_back({i.first, i.second});
        }

        sort(v.begin(), v.end(), comp);
        string res = "";
        for (auto p : v)
        {
            int n = p.second;
            while (n--)
            {
                res += p.first;
            }
        }
        return res;
    }
};