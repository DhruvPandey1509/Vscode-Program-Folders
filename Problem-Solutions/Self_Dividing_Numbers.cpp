#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool selfDividing(int num)
    {
        int temp = num;
        while (num > 0)
        {
            int rem = num % 10;
            if (rem == 0)
                return false;
            if (temp % rem != 0)
                return false;

            num /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;

        for (int i = left; i <= right; i++)
        {
            if (selfDividing(i))
                res.push_back(i);
        }

        return res;
    }
};