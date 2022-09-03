#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> res;
    void solve(int len, int &k, int num, int curr_digit)
    {
        // (Base Case) is len = 0 that means we have num that holds true for the condition
        if (len == 0)
        {
            res.push_back(num);
            return;
        }

        // for other digits we can have combination from 0-9
        for (int i = 0; i < 10; i++)
        {
            if (abs(i - curr_digit) == k)
            {
                solve(len - 1, k, num * 10 + i, i);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        // solving for every possible number that can start with the digits 1-9
        for (int i = 1; i <= 9; i++)
        {
            solve(n - 1, k, i, i);
        }

        return res;
    }
};