#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {

        int n = arr.size();
        if (n % 2 != 0)
        {
            return false;
        }

        unordered_map<int, int> m; // first = remainder  , second = frequency
        int rem;
        for (int i = 0; i < n; i++)
        {
            rem = arr[i] % k;

            // to handle negative number as they have negative remainders
            if (rem < 0)
            {
                m[rem + k]++;
            }
            else
            {
                m[arr[i] % k]++;
            }
        }

        for (auto x : m)
        {
            if (x.first == 0)
            {
                if (x.second % 2 != 0)
                {
                    return false;
                }
            }
            else
            {
                int num = x.first;
                auto it = m.find(k - num);
                if (it == m.end())
                {
                    return false;
                }
                else
                {
                    if ((*it).second != x.second)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};