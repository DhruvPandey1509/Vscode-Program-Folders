#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &a)
    {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int sum = 0;
            int count = 1;
            for (int j = i; j < a.size(); j++)
            {
                sum += a[j];
                if (!(count % 2 == 0))
                {
                    res += sum;
                }
                count++;
            }
        }
        return res;
    }
};