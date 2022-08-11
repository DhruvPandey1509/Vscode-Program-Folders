#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        if (s.size() == 0)
            return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;

        int child = 0;
        while (i < g.size() and j < s.size())
        {
            if (g[i] <= s[j])
            {
                child++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        return child;
    }
};