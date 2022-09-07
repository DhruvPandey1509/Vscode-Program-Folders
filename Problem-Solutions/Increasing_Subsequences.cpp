#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    set<vector<int>> s;
    void solve(vector<int> nums, int idx, int prev, vector<int> v)
    {
        if (v.size() != 0 and v.size() != 1)
            s.insert(v);

        for (int i = idx; i < nums.size(); i++)
        {
            if (nums[i] >= prev)
            {
                v.push_back(nums[i]);
                solve(nums, i + 1, nums[i], v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> v;
        solve(nums, 0, INT_MIN, v);

        vector<vector<int>> res;
        for (auto i : s)
        {
            res.push_back(i);
        }

        return res;
    }
};
