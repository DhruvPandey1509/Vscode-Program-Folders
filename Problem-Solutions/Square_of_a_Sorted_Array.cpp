#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {

        int st = 0, en = nums.size() - 1;

        vector<int> res(en + 1);
        int idx = en;

        while (idx >= 0)
        {
            if (pow(nums[st], 2) > pow(nums[en], 2))
            {
                res[idx] = pow(nums[st], 2);
                st++;
            }
            else
            {
                res[idx] = pow(nums[en], 2);
                en--;
            }

            idx--;
        }

        return res;
    }
};