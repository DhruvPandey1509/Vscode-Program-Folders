#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int lcount = 0;
        int rcount = 0;
        int res = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                lcount++;
            else if (s[i] == 'R')
                rcount++;

            if (lcount == rcount)
            {
                res++;
            }
        }

        return res;
    }
};