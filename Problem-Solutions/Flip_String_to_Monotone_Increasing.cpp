#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int totalZero = 0;
        int leftOne = 0;
        int rightZero = 0;

        int n = s.size();
        for (auto i : s)
        {
            if (i == '0')
            {
                totalZero++;
            }
        }

        rightZero = totalZero;
        int res = rightZero;

        for (auto i : s)
        {
            if (i == '0')
            {
                rightZero--;
            }
            else
            {
                leftOne++;
            }
            res = min(res, leftOne + rightZero);
        }

        return res;
    }
};