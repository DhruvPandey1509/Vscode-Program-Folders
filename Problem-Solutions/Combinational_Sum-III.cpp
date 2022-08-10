#include "bits/stdc++.h"
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> v;

public:
    void solve(int k, int n, int i)
    {
        if (n == 0 and v.size() == k)
        {
            res.push_back(v);
            return;
        }

        for (int j = i; j <= 9; j++)
        {
            v.push_back(j);
            solve(k, n - j, j + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        solve(k, n, 1);
        return res;
    }
};