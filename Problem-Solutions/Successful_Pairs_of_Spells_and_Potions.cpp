#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> v;
        for (int i = 0; i < spells.size(); i++)
        {
            int l = 0, r = n - 1;
            int mid;
            while (l <= r)
            {
                mid = l + (r - l) / 2;

                if ((long long int)spells[i] * (long long int)potions[mid] >= success)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            v.push_back(n - 1 - r);
        }

        return v;
    }
};
