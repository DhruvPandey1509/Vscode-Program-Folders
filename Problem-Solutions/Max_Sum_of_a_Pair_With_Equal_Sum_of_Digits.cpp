#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int sumOfDigits(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int> &nums)
    {
        vector<vector<int>> v(91);
        int ans = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            v[sumOfDigits(nums[i])].push_back(nums[i]);
        }

        for (int i = 0; i <= 90; i++)
        {
            if (v[i].size() <= 1)
                continue;

            sort(v[i].begin(), v[i].end());
            reverse(v[i].begin(), v[i].end());

            ans = max(ans, v[i][0] + v[i][1]);
        }

        return ans;
    }
};