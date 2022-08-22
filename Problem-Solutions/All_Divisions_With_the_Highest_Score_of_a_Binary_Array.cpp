#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        int zero = 0, one = 0;

        for (auto i : nums)
        {
            if (i == 1)
                one++;
        }

        int curr_max = 0 + one;
        multimap<int, int> m;
        m.insert({curr_max, 0});

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zero++;
            }
            else if (nums[i] == 1)
            {
                one--;
            }

            if (curr_max < one + zero)
            {
                auto it = m.find(curr_max);
                auto it2 = m.find(curr_max + 1);
                m.erase(it, it2);

                curr_max = one + zero;
                m.insert({curr_max, i + 1});
            }
            else if (curr_max == one + zero)
            {
                m.insert({curr_max, i + 1});
            }
        }

        vector<int> v;
        for (auto i : m)
        {
            v.push_back(i.second);
        }

        return v;
    }
};
