#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = nums[i];
        }
        sort(v.begin(), v.end());
        int l = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != nums[i])
            {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] != nums[i])
            {
                r = i;
                break;
            }
        }
        if (l == r)
        {
            return 0;
        }
        return r - l + 1;
    }
};