#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {

        unordered_map<int, int> m;
        vector<int> res;
        for (auto i : nums1)
        {
            m[i] = 1;
        }

        for (auto i : nums2)
        {
            if (m[i] == 1)
            {
                res.push_back(i);
                m[i] = -1;
            }
            else if (m[i] != -1)
            {
                m[i] = 2;
            }
        }

        for (auto i : nums3)
        {
            if (m[i] == 2 || m[i] == 1)
            {
                res.push_back(i);
                m[i] = 0;
            }
        }

        return res;
    }
};