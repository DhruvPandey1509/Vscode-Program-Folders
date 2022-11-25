#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        unordered_map<int, int> m;
        int prefix_sum = 0;
        int max_len = 0;
        int rem = 0;
        m[0] = -1;
        for (int i = 0; i < n; i++)
        {
            prefix_sum += arr[i];
            rem = prefix_sum % k;
            if (rem < 0)
                rem += k;
            if (m.find(rem) != m.end())
            {
                max_len = max(max_len, i - m[rem]);
            }
            else
            {
                m[rem] = i;
            }
        }

        return max_len;
    }
};