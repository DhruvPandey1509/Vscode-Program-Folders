#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size(), r = n - 1;

        while (r > 0 and arr[r - 1] <= arr[r])
            --r;

        int res = r;

        for (int i = 0; i < r and (i == 0 or arr[i - 1] <= arr[i]); i++)
        {
            while (r < n and arr[r] < arr[i])
                ++r;

            res = min(res, r - i - 1);
        }
        return res;
    }
};
