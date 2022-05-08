#include "bits/stdc++.h"
using namespace std;
#define ll long long
class Solution
{
public:
    // Function to check if two arrays are equal or not.
    bool check(vector<ll> a, vector<ll> b, int n)
    {
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[a[i]]++;
            m[b[i]]--;
        }

        for (auto x : m)
        {
            if (x.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};