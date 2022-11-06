#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            int st = i;
            while (st < n and nums[st] == 0)
                st++;

            int en = st;
            int negative_count = 0;
            int first_negative_idx = -1;
            int last_negative_idx = -1;

            while (en < n and nums[en] != 0)
            {
                if (nums[en] < 0)
                {
                    negative_count++;
                    if (first_negative_idx == -1)
                    {
                        first_negative_idx = en;
                    }
                    last_negative_idx = en;
                }
                en++;
            }

            if (negative_count % 2 == 0)
            {
                res = max(res, en - st);
            }
            else
            {
                if (first_negative_idx != -1)
                    res = max(res, en - first_negative_idx - 1);
                if (last_negative_idx != -1)
                    res = max(res, last_negative_idx - st);
            }

            i = en + 1;
        }

        return res;
    }
};
