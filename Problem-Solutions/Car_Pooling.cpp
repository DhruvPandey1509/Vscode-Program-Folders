#include "bits/stdc++.h"
using namespace std;

// Approach 1 T.C = O(nlogn)
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        map<int, int> m;
        for (vector<int> v : trips)
        {
            int st = v[1];
            int en = v[2];
            m[st] += v[0];
            m[en] -= v[0];
        }

        int sum = 0;
        for (auto i : m)
        {
            sum += i.second;
            if (sum > capacity)
                return false;
        }
        return true;
    }
};

// Approach 2 T.C = O(n)
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> m(1001, 0);

        for (vector<int> v : trips)
        {
            int st = v[1];
            int en = v[2];
            m[st] += v[0];
            m[en] -= v[0];
        }

        int sum = capacity;
        for (int i = 0; i < 1001 and sum >= 0; i++)
        {
            sum -= m[i];
        }

        return sum >= 0;
    }
};