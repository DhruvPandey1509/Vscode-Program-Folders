#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        if (n % 2 != 0)
        {
            return false;
        }

        for (int i = 0; i < n; i++)
        {
            m[nums[i] % k]++;
        }

        for (auto i : m)
        {
            if (i.first == 0)
            {
                if (i.second % 2 != 0)
                {
                    return false;
                }
            }
            else
            {
                int a = i.first;
                auto it = m.find(k - a);
                if (it == m.end())
                {
                    return false;
                }
                else
                {
                    if ((*it).second != i.second)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};