#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        // if freq of a and b is equal
        if (a.second == b.second)
        {
            // if value of a is greater than b no need to reorder
            return a.first > b.first;
        }
        // if freq of a is less than freq of b no need to reorder
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int> &nums)
    {

        map<int, int> m; // key = number  value = frequency
        vector<pair<int, int>> temp;
        for (auto i : nums)
        {
            m[i]++;
        }

        for (auto i : m)
        {
            temp.push_back(i);
        }

        sort(temp.begin(), temp.end(), cmp);

        vector<int> res;
        for (auto i : temp)
        {
            int n = i.second;
            while (n--)
            {
                res.push_back(i.first);
            }
        }

        return res;
    }
};