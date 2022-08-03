#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.size();
        if (n < 10)
            return {};

        unordered_map<string, int> m;

        for (int i = 0; i < n; i++)
        {
            m[s.substr(i, 10)]++;
        }
        vector<string> res;
        for (auto i : m)
        {
            if (i.second > 1)
                res.push_back(i.first);
        }

        return res;
    }
};