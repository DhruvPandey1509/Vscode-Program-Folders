#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxCoins(int a[], int b[], int t, int n)
    {
        if (t == 0 || n == 0)
        {
            return 0;
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({b[i], a[i]});
        }
        sort(v.begin(), v.end());

        int res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (t > v[i].second)
            {
                res += v[i].first * v[i].second;
                t -= v[i].second;
            }
            else
            {
                res += v[i].first * t;
                break;
            }
        }
        return res;
    }
};