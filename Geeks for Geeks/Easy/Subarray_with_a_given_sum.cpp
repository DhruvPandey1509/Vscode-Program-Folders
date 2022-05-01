#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int a[], int n, long long s)
    {
        int st = 0;
        int en = 0;
        long long sum = 0;
        while (en < n)
        {
            sum += a[en];
            en++;
            while (sum > s and st < en)
            {
                sum -= a[st];
                st++;
            }
            if (sum == s)
            {
                return {st + 1, en};
            }
        }

        return {-1};
    }
};