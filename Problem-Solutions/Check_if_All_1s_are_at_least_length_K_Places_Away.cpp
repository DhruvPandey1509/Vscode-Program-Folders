#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int count = 0;
        int i = 0;

        while (i < nums.size() and nums[i] != 1)
        {
            i++;
        }
        i++;
        while (i < nums.size())
        {
            if (nums[i] == 0)
                count++;

            if (nums[i] == 1)
            {
                if (count >= k)
                {
                    count = 0;
                }
                else
                {
                    return false;
                }
            }
            i++;
        }

        return true;
    }
};