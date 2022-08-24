#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {

        int res = 0;
        int n = nums.size();

        while (1)
        {
            int count = 0, countZero = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] % 2 != 0)
                {
                    nums[i] -= 1; // decrease the odd number by one
                    res++;
                }
                else
                {
                    count++; // count the even numbers in array
                }
                if (nums[i] == 0)
                {
                    countZero++; // count the zeros in array
                }
            }

            if (countZero == n)
            {
                return res;
            }

            if (count == n)
            {
                res++;
                for (int i = 0; i < n; i++)
                {
                    nums[i] /= 2;
                }
            }
        }
        return res;
    }
};
