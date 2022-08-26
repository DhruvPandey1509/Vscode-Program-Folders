#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    unordered_map<int, vector<int>> m;
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        vector<int> res;
        int rows = nums.size() - 1;
        int cols = 0;
        for (auto i : nums)
        {
            cols = max(cols, i.size());
        }
        cols--;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                m[i + j].push_back(nums[i][j]);
            }
        }

        for (int sum = 0; sum <= rows + cols; sum++)
        {
            vector<int> v = m[sum];
            reverse(v.begin(), v.end());
            for (auto i : v)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};
