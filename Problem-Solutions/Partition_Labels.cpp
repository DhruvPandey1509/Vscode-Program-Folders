#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> v(26, 0);
        vector<int> res;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            v[s[i] - 'a'] = i;
        }
        int l = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            r = max(r, v[s[i] - 'a']);
            if (r == i)
            {
                res.push_back(r - l + 1);
                l = r + 1;
            }
        }

        return res;
    }
};