#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void func(vector<vector<int>> &res, vector<int> v, vector<int> nums, int idx)
    {
        res.push_back(v);

        for (int i = idx; i < nums.size(); i++)
        {
            v.push_back(nums[i]);
            func(res, v, nums, i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> res;
        vector<int> v;
        func(res, v, nums, 0);
        return res;
    }
};