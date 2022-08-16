#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> v(26, 0);
        vector<char> odr;

        for (char c : order)
        {
            odr.push_back(c);
        }

        for (char c : s)
        {
            v[c - 'a']++;
        }

        string res = "";
        for (char c : odr)
        {
            while (v[c - 'a'] > 0)
            {
                res += c;
                v[c - 'a']--;
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            while (v[i] > 0)
            {
                res += 'a' + i;
                v[i]--;
            }
        }

        return res;
    }
};