#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        // we will check for maximum of  1.) starting two numbers as elements can be negative so their product will give as positive and multiplying with last element 2.) last 3 elements.
        // if the whole array is negative this will hold valid for that too
        return max(nums[0] * nums[1] * nums[n], nums[n] * nums[n - 1] * nums[n - 2]);
    }
};