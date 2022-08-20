#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> beautifulArray(int n)
    {
        if (n == 1)
            return {1};

        vector<int> res = {1};
        while (res.size() < n)
        {
            vector<int> temp;

            for (auto i : res)
            {
                if ((i * 2) - 1 <= n)
                {
                    temp.push_back(i * 2 - 1);
                }
            }
            for (auto j : res)
            {
                if ((j * 2) <= n)
                {
                    temp.push_back(j * 2);
                }
            }

            res = temp;
        }
        return res;
    }
};