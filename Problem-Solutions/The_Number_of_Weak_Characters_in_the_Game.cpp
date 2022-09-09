#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0])
            return a[0] > b[0];

        return a[1] < b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>> &p)
    {
        sort(p.begin(), p.end(), cmp);
        int mx = INT_MIN;
        int res = 0;
        for (auto i : p)
        {
            if (mx > i[1])
                res++;
            else
                mx = i[1];
        }

        return res;
    }
};
