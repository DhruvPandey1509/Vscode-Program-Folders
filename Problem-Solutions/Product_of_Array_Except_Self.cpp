#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int total_product = 1;
        int non_zero_product = 0;
        bool flag = false; // 0 num not present in nums
        int zeroCount = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                non_zero_product = 1;
                break;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                non_zero_product *= nums[i];
            }
            else
            {
                total_product = 0;
                zeroCount++;
            }
        }

        if (total_product == 1)
        {
            total_product = non_zero_product;
            flag = true;
        }

        if (flag)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                nums[i] = total_product / nums[i];
            }
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] != 0)
                {
                    nums[i] = 0;
                }
                else
                {
                    if (zeroCount > 1)
                    {
                        nums[i] = 0;
                    }
                    else
                    {
                        nums[i] = non_zero_product;
                    }
                }
            }
        }

        return nums;
    }
};