#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};
        if (nums.size() == 1)
            return {to_string(nums[0])};

        int st, en;
        string prev;

        st = nums[0];
        prev = to_string(st);

        int i = 1;
        vector<string> res;

        while (i < nums.size())
        {
            en = nums[i];
            if (to_string(en - 1) == prev)
            {
                prev = to_string(en);
                i++;
            }
            else
            {
                if (prev != to_string(st))
                {
                    string s = to_string(st) + "->" + prev;
                    res.push_back(s);
                }

                else
                {
                    res.push_back(prev);
                }

                st = en;
                prev = to_string(st);
                i++;
            }
        }
        if (prev != to_string(st))
        {
            string s = to_string(st) + "->" + prev;
            res.push_back(s);
        }

        else
        {
            res.push_back(prev);
        }

        return res;
    }
};