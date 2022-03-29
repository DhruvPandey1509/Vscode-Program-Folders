#include "bits/stdc++.h"
using namespace std;
class Solution
{
    vector<int> v = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

public:
    int val(int n)
    {
        int digit, sum = 0;

        while (n > 0)
        {
            digit = n % 10;
            sum += v[digit];
            n /= 10;
        }

        return sum;
    }
    unordered_set<int> res;
    bool isHappy(int n)
    {
        if (n == 1)
        {
            return true;
        }

        n = val(n);
        if (res.find(n) != res.end())
            return false;
        res.insert(n);
        return isHappy(n);
    }
};