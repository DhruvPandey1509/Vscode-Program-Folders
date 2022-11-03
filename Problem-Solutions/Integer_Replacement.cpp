#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int integerReplacement(int n)
    {
        int count = 0;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                if (n == INT_MAX)
                {
                    count++;
                    n /= 2;
                    n++;
                }
                else if (n == 3)
                    n--;
                else if ((n + 1) % 4)
                    n--;
                else
                    n++;
            }
            count++;
        }
        return count;
    }
};