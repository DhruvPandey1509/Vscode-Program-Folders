#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
class Solution
{
public:
    int maxArea(int h, int w, vector<int> &hC, vector<int> &vC)
    {

        hC.push_back(h);
        vC.push_back(w);

        sort(hC.begin(), hC.end());
        sort(vC.begin(), vC.end());

        int max_height = hC[0];
        for (int i = 1; i < hC.size(); i++)
        {
            max_height = max(max_height, hC[i] - hC[i - 1]);
        }

        int max_width = vC[0];
        for (int i = 1; i < vC.size(); i++)
        {
            max_width = max(max_width, vC[i] - vC[i - 1]);
        }

        return (max_height * 1LL * max_width) % MOD;
    }
};