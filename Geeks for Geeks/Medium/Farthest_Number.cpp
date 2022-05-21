#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> farNumber(int n, vector<int> a)
    {
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            int idx = -1;
            for (int j = n - 1; j > i; j--)
            {
                if (a[j] < a[i])
                {
                    idx = j;
                    break;
                }
            }
            res.push_back(idx);
        }
        return res;
    }
};