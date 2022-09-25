#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isMatching(string s, string &p)
    {
        int j = 0;
        for (char c : s)
        {
            if (c >= 'A' and c <= 'Z' and c != p[j])
                return false;
            if (c == p[j])
                j++;
        }

        return j == p.size();
    }

    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> res;
        for (auto q : queries)
        {
            res.push_back(isMatching(q, pattern));
        }

        return res;
    }
};