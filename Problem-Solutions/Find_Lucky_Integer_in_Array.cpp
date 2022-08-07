#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        unordered_map<int, int> m;

        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }

        int res = -1;
        for (auto i : m)
        {
            if (i.first == i.second)
            {
                res = max(res, i.first);
            }
        }

        return res;
    }
};