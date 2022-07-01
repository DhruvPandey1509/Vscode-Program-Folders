#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string solve(string s, int pos, int k)
    {
        string s1 = s.substr(pos, k);
        reverse(s1.begin(), s1.end());
        return s1;
    }
    string reverseStr(string s, int k)
    {
        if (s.length() <= k)
        {
            reverse(s.begin(), s.end());
            return s;
        }
        string res = "";
        int pos = 0;
        int count = 0;
        int r = 2 * k;
        int i = 0;
        while (i < s.size())
        {
            if (count % r == 0)
            {
                pos = i;
                string s1 = solve(s, pos, k);
                res = res.append(s1);
                i += k;
                count += k;
            }
            else
            {
                while (i < s.size() && count % r != 0)
                {
                    res += s[i];
                    count++;
                    i++;
                }
            }
        }
        return res;
    }
};