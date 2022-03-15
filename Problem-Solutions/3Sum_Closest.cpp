#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());
        int sum;
        int ans = 0;
        int diff = INT_MAX;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                sum = nums[i] + nums[j] + nums[k];

                if (diff > abs(target - sum))
                {
                    ans = sum;
                    diff = abs(target - sum);
                }

                if (sum == target)
                    return sum;
                else if (sum > target)
                    k--;
                else
                    j++;
            }
        }

        return ans;
    }
};