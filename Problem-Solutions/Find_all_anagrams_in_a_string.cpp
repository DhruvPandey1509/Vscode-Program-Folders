#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (p.size() > s.size())
            return {};
        int n = p.size();
        vector<int> pmap(26, 0);
        vector<int> v(26, 0);

        for (int i = 0; i < p.size(); i++)
        {
            pmap[p[i] - 'a']++;
            v[s[i] - 'a']++;
        }

        if (v == pmap)
            res.push_back(0);

        int l = 0;
        for (int i = n; i < s.size(); i++)
        {
            v[s[l] - 'a']--;
            v[s[i] - 'a']++;
            l++;
            if (v == pmap)
            {
                res.push_back(l);
            }
        }

        return res;
    }
};