#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int sum = 0;

        int max_len = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : 1;

            if (sum == 0)
            {
                if (max_len < i + 1)
                    max_len = i + 1;
            }
            else if (m.find(sum) != m.end())
            {
                max_len = max(max_len, i - m[sum]);
            }
            else
            {
                m[sum] = i;
            }
        }

        return max_len;
    }
};