#include "bits/stdc++.h"
using namespace std;

// Method 1 :- using STL
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do
        {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return res;
    }
};

// Method 2 :-
class Solution1
{
public:
    vector<vector<int>> res;

    void solve(vector<int> nums, int index)
    {
        if (nums.size() == index)
        {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        solve(nums, 0);
        return res;
    }
};