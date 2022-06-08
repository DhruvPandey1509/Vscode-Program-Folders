#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to return the sorted array.
    vector<int> nearlySorted(int a[], int n, int K)
    {
        priority_queue<int, vector<int>, greater<int>> p;

        for (int i = 0; i < n; i++)
        {
            p.push(a[i]);
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(p.top());
            p.pop();
        }

        return res;
    }
};