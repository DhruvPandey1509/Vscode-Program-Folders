#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        long count = 0;
        unordered_map<int, long> m;
        for (auto i : nums)
        {
            m[i - rev(i)]++;
        }
        for (auto i : m)
        {
            count = (count + (i.second * (i.second - 1)) / 2) % 1000000007;
        }

        return count;
    }
    int rev(int n)
    {
        int revNum = 0;
        while (n)
            revNum = revNum * 10 + (n % 10), n /= 10;
        return revNum;
    }
};