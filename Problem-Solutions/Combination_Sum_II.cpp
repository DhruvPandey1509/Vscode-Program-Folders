#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    void solve(vector<int> &c, vector<int> &v, int target, int idx)
    {
        if (target == 0)
        {
            res.push_back(v);
            return;
        }

        for (int i = idx; i < c.size(); i++)
        {
            if (c[i] > target)
                break;

            if (i > idx and c[i] == c[i - 1])
                continue;

            v.push_back(c[i]);
            solve(c, v, target - c[i], i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        solve(candidates, v, target, 0);
        return res;
    }
};