#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> sumClosest(vector<int> arr, int x)
    {
        vector<int> res(2, 1);
        int i = 0;
        int j = arr.size() - 1;
        int diff = INT_MAX;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (abs(sum - x) < diff)
            {
                diff = abs(sum - x);
                res[0] = arr[i];
                res[1] = arr[j];
            }

            if (sum > x)
                j--;
            else
                i++;
        }

        return res;
    }
};