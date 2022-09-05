#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        map<int, int> m;
        vector<int> v;

        for (auto i : arr)
        {
            m[i]++;
        }

        for (auto i : m)
        {
            v.push_back(i.second);
        }

        sort(v.begin(), v.end());
        int i = 0;
        for (i; i < v.size(); i++)
        {
            if (k >= v[i])
            {
                k -= v[i];
            }
            else
                break;
        }

        return v.size() - i;
    }
};
