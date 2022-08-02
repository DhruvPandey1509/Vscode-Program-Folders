#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s1;
        set<int> s2;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++)
        {
            s1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            s2.insert(nums2[i]);
        }

        for (auto &i : s1)
        {
            if (s2.find(i) != s2.end())
                res.push_back(i);
        }

        return res;
    }
};