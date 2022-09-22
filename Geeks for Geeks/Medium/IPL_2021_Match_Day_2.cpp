#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> max_of_subarrays(vector<int> nums, int n, int k)
    {

        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() and dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() and nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};