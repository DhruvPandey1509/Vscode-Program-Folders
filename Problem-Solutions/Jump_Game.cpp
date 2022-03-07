#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        if (nums.size() == 1)
        {
            return true;
        }

        int reach = 0;

        int n = nums.size() - 1;

        for (int i = 0; i <= n; i++)
        {

            reach = max(reach, i + nums[i]);
            if (reach == i)
            {
                return false;
            }

            else
            {
                if (reach >= n)
                {
                    return true;
                }
            }
        }

        return true;
    }
};
//Another Way
class Solution {
public:
    bool canJump(vector<int>& nums) {
       
        int n = nums.size();
        vector<bool> dp(n, 0);
        dp[0] = true;
        for(int i = 1; i < n; i++)
        {
            for(int j = i-1; j >=0; j--)
            {
                if(dp[j] && j+nums[j] >= i)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n-1];
       
    }
};