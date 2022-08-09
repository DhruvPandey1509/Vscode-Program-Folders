#include "bits/stdc++.h"
using namespace std;

// Find a subarray with sum = S (total sum of array) - X ( given )
// Next thing, we wanna do is to maximize the length of sub array
// Above points are quite logical so read them again and think why ?
// Return ( array size - size of max subarray with sum S - X )
// Use Sliding Window technique to keep your code away from getting TLE

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        sum -= x;
        if (sum == 0)
            return nums.size();
        else if (sum < 0)
            return -1;

        int st = 0, total = 0;
        int count = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
            while (total > sum)
            {
                total = total - nums[st];
                st++;
            }

            if (sum == total)
            {
                count = max(count, i - st + 1);
            }
        }
        if (count < 0)
            return -1;

        return nums.size() - count;
    }
};