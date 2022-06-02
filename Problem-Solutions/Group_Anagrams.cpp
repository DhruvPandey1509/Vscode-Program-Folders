#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &s)
    {

        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            string a = s[i];
            sort(a.begin(), a.end());
            m[a].push_back(s[i]);
        }

        for (auto i : m)
        {
            res.push_back(i.second);
        }

        return res;
    }
};