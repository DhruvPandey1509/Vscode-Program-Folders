#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    // Function to return the largest possible number of n digits
    // with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        string res = "";
        int i = 9;
        while (i >= 0 && n > 0)
        {
            while (sum - i < 0)
            {
                i--;
            }
            sum -= i;
            res += to_string(i);
            n--;
        }

        if (n == 0 && sum != 0)
        {
            return "-1";
        }
        while (n > 0)
        {
            res += "0";
            n--;
        }
        return res;
    }
};