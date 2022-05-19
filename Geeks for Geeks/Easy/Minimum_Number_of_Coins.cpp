#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> denoms = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> minPartition(int num)
    {
        vector<int> res;
        int n = denoms.size() - 1;

        while (num >= 0 and n >= 0)
        {
            while (num - denoms[n] >= 0)
            {
                res.push_back(denoms[n]);
                num = num - denoms[n];
            }
            n--;
        }
        return res;
    }
};