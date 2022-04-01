#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size(), j, k;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            j = i + 1;
            k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (k != -1 && nums[k + 1] == nums[k])
                        k--;

                    while (j != n && nums[j - 1] == nums[j])
                        j++;
                }
                else if (sum > 0)
                {
                    k--;
                    while (k != -1 && nums[k + 1] == nums[k])
                        k--;
                }
                else
                {
                    j++;
                    while (j != n && nums[j - 1] == nums[j])
                        j++;
                }
            }
        }
        return res;
    }
};