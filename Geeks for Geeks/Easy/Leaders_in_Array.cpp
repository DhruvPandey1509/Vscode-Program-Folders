#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> res;
        res.push_back(a[n - 1]);
        int maxNum = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] >= maxNum)
            {
                res.push_back(a[i]);
                maxNum = a[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};