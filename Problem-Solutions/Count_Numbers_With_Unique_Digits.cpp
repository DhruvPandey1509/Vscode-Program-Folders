#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        int count = 1;

        for (int i = 0; i < n; i++)
        {
            int temp = 9;
            for (int j = 0; j < i; j++)
            {
                temp *= (9 - j);
            }

            count += temp;
        }

        return count;
    }
};

class Solution1 {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        
        int res = 10;
        int count = 9;
        int start = 9;
        n -= 1;
        while(n-- and start)
        {
            count *= start;
            start--;
            res += count;
        }
        
        return res;
    }
};