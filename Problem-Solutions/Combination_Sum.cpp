#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void solve(vector<int> &candidates, vector<vector<int>> &res, vector<int> &temp, int target, int x)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        if (target < 0 || x > candidates.size())
        {
            return;
        }

        for (int i = x; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            solve(candidates, res, temp, target - candidates[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> res;
        vector<int> temp;

        solve(candidates, res, temp, target, 0);

        return res;
    }
};