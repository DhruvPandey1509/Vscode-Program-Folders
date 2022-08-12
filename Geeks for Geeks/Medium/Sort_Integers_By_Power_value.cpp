#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    typedef pair<int, int> pi;
    vector<int> dp;
    int power(int x)
    {
        if (x == 1)
            return 0;
        int count = 0;
        while (x != 1)
        {
            if (dp[x] != -1)
                return count + dp[x];

            if (x % 2 == 0)
            {
                x = x / 2;
            }
            else
            {
                x = (3 * x) + 1;
            }
            count++;
        }

        return count;
    }
    int getKth(int lo, int hi, int k)
    {

        dp.assign(1000000, -1);
        priority_queue<pi, vector<pi>, greater<pi>> p;

        for (int i = lo; i <= hi; i++)
        {
            int pwr = power(i);
            p.push({pwr, i});
        }

        while (--k) //--k == k-1 and then k--. it will first be reduced by 1 then it will continue the loop
        {
            p.pop();
        }

        return p.top().second;
    }
};