#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int countZero = 0;
        int i = 0;
        int maxLen = INT_MIN;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == 0)
                countZero++;

            while (countZero > 1)
            {
                if (nums[i] == 0)
                {
                    countZero--;
                }
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen - 1;
    }
};
