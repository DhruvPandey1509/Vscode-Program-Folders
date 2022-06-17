#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string removeDups(string s)
    {
        int n = s.size();
        if (n == 1)
            return s;

        string res = "";
        vector<int> v(26, 0);

        for (int i = 0; i < n; i++)
        {
            if (v[s[i] - 'a'] == 0)
            {
                res += s[i];
                v[s[i] - 'a']++;
            }
        }

        return res;
    }
};