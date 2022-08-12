#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool check(vector<int> v, int target, int d)
    {
        int lo = 0, hi = v.size() - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (abs(v[mid] - target) <= d)
                return false;

            if (v[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return true;
    }
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {

        sort(arr2.begin(), arr2.end());
        int count = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            if (check(arr2, arr1[i], d))
            {
                count++;
            }
        }

        return count;
    }
};