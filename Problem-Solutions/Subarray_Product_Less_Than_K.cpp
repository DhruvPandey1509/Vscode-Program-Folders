#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int left = 0, right = 0;
        int count = 0, product = 1;

        for (int right = 0; right < nums.size(); right++)
        {
            product *= nums[right];

            while (left < right and product >= k)
            {
                product /= nums[left];
                left++;
            }

            if (product < k)
                count += right - left + 1;
        }

        return count;
    }
};
