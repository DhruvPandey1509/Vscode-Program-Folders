#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        vector<int> res(2, 0);
        int w = 0, i = 0;

        for (i = 0; i < s.size(); i++)
        {
            w += widths[s[i] - 'a'];
            if (w > 100)
            {
                i--;
                res[0]++;
                res[1] = w;
                w = 0;
            }
        }

        res[0]++;
        res[1] = w;
        return res;
    }
};