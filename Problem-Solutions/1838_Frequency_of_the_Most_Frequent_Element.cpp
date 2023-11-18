#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long l = 0, r = 0;
        long totalSum = 0, res = 0;
        while (r < n)
        {
            totalSum += nums[r];
            while (nums[r] * (r - l + 1) > totalSum + k)
            {
                totalSum -= nums[l];
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};