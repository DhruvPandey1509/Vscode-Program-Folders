#include "bits/stdc++.h"
using namespace std;
#define ll long long
class Solution
{
public:
    // Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n)
    {
        vector<int> pre(n + 1, 0);
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + arr[i];
            if (m.find(pre[i + 1]) != m.end())
            {
                res += m[pre[i + 1]];
            }
            m[pre[i + 1]]++;
        }

        return res;
    }
};