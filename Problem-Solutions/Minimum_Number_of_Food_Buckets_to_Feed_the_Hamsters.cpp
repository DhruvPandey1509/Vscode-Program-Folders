#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int minimumBuckets(string street)
    {
        int n = street.size();
        int ans = 0;
        for (int i = 0; i < n;)
        {
            if (street[i] == 'H')
            {
                if (i + 1 < n and street[i + 1] == '.')
                {
                    ans++;
                    i += 3;
                }
                else if (i > 0 and street[i - 1] == '.')
                {
                    ans++;
                    i++;
                }
                else
                    return -1;
            }

            else
                i++;
        }
        return ans;
    }
};
