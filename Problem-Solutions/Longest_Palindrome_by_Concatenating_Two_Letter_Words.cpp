#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        map<string, int> m;
        for (auto word : words)
        {
            m[word]++;
        }
        int res = 0;
        bool flag = false;

        for (auto i : m)
        {
            string s = i.first;
            string t = s;
            reverse(t.begin(), t.end());

            if (s == t)
            {
                res += (i.second / 2);
                if (i.second % 2)
                {
                    flag = true;
                }
            }
            else
            {
                if (m.count(t))
                {
                    res += min(i.second, m[t]);
                    m.erase(t);
                }
            }
        }
        res = res * 4;
        if (flag)
            res += 2;
        return res;
    }
};
