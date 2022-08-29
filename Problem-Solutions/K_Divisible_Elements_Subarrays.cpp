#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int n = nums.size();
        set<vector<int>> res;

        int i, j;
        for (i = 0; i < n; i++)
        {
            vector<int> v;
            int count = 0;
            for (j = i; j < n; j++)
            {
                v.push_back(nums[j]);
                if (nums[j] % p == 0)
                    count++;
                if (count > k)
                    break;
                res.insert(v);
            }
        }
        return res.size();
    }
};
