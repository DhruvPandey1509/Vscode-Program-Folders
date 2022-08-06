#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        unordered_map<int, int> m;

        int alice = 0;
        int bob = 0;

        for (int i = 0; i < aliceSizes.size(); i++)
        {
            alice += aliceSizes[i];
        }
        for (int i = 0; i < bobSizes.size(); i++)
        {
            bob += bobSizes[i];
            m[bobSizes[i]]++;
        }

        int req = (alice + bob) / 2;
        if (alice == req and bob == req)
            return {0, 0};

        for (int i = 0; i < aliceSizes.size(); i++)
        {
            if (m.find(req - (alice - aliceSizes[i])) != m.end())
            {
                return {aliceSizes[i], req - (alice - aliceSizes[i])};
            }
        }

        return {};
    }
};