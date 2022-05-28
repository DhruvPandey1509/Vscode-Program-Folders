#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            v[nums[i]]++;
        }
        int missingNum;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 0)
            {
                missingNum = i;
                break;
            }
        }
        return missingNum;
    }
};