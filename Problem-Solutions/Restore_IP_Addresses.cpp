#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> res;
    void backtrack(string s, vector<string> &v, int idx)
    {
        int m = v.size(), n = s.size();
        if (idx == n and m == 4)
        {
            res.push_back(v[0] + '.' + v[1] + '.' + v[2] + '.' + v[3]);
            return;
        }
        if (idx > n or m > 4)
        {
            return;
        }

        for (int i = 0; i < 3; i++)
        {
            if (idx + i <= n - 1)
            {
                string str = s.substr(idx, i + 1);
                if ((i == 0 and str >= "0" and str <= "9") or (i == 1 and str >= "10" and str <= "99") or (i == 2 and str >= "100" and str <= "255"))
                {
                    v.push_back(str);
                    for (auto i : v)
                    {
                        cout << i << endl;
                    }
                    backtrack(s, v, idx + i + 1);
                    v.pop_back();
                }
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> v;
        backtrack(s, v, 0);
        return res;
    }
};