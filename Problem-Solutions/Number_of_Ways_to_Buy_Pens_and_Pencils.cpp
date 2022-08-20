#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2)
    {

        long int ans = 0;
        int n1 = total / cost1;
        int n2 = total / cost2;

        if (n1 == 0 && n2 == 0)
        {
            return 1;
        }

        if (n1 == 0)
        {
            return n2 + 1;
        }

        if (n2 == 0)
        {
            return n1 + 1;
        }

        for (int i = 0; i <= n1; ++i)
        {
            int costi = total - i * cost1;
            ans += (costi / cost2) + 1;
        }

        return ans;
    }
};