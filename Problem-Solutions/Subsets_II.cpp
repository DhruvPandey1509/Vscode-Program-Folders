#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;        // to store all susbets
        vector<int> v;                  // to store current individual subset (that we will build)
        sort(nums.begin(), nums.end()); // sort the array so that duplicates are adjacent
        makeSubset(nums, v, 0);         // we start from index 0
        return res;
    }

    void makeSubset(vector<int> &nums, vector<int> &v, int idx)
    {
        res.push_back(v); // we include current susbet into final ans
        for (int i = idx; i < nums.size(); i++)
        { // check for all possibilites
            if (i > idx && nums[i] == nums[i - 1])
                continue;         // if duplicate then we continue
            v.push_back(nums[i]); // we include nums[i] in current subset
            makeSubset(nums, v, i + 1);
            v.pop_back(); // to get subset without nums[i]
        }
    }
};