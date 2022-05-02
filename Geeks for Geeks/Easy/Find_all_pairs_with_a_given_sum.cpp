#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> allPairs(int a[], int b[], int n, int m, int x)
    {
        int l1 = 0;
        int h2 = m - 1;
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
        {
            while (h2 >= 0)
            {
                if (a[i] + b[h2] == x)
                {
                    p.push_back({a[i], b[h2]});
                }
                h2--;
            }
            h2 = m - 1;
        }
        sort(p.begin(), p.end());

        return p;
    }
};