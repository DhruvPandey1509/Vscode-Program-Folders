#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {

        for (int i = 0; i < nums.size() - 1; i++)
        {
            // nums[i] = even and i = odd
            if (nums[i] % 2 == 0 and i % 2 != 0)
            {
                int j = i + 1;
                while (j < nums.size())
                {
                    if (nums[j] % 2 != 0)
                        break;

                    j += 2;
                }
                if (j < nums.size() and nums[j] % 2 != 0)
                {
                    swap(nums[i], nums[j]);
                }
            }

            // nums[i] = odd and i = even
            if (nums[i] % 2 != 0 and i % 2 == 0)
            {
                int j = i + 1;
                while (j < nums.size())
                {
                    if (nums[j] % 2 == 0)
                        break;

                    j += 2;
                }
                if (j < nums.size() and nums[j] % 2 == 0)
                {
                    swap(nums[i], nums[j]);
                }
            }
        }

        return nums;
    }
};