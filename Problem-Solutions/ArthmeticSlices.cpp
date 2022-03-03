#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {

        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2)
        {
            return 0;
        }

        int ans = 0;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int count = 0;
            int diff = nums[i] - nums[i + 1];
            for (int j = i + 1; j < nums.size() - 1; j++)
            {

                if (nums[j] - nums[j + 1] == diff)
                {
                    count++;
                }
                else if (nums[j] - nums[j + 1] != diff)
                {
                    break;
                }

                if (count >= 1)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};