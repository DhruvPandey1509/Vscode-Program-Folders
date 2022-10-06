#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> res(n, 0);
        for (int i = 0; i < bookings.size(); i++)
        {
            int first = bookings[i][0] - 1;
            int last = bookings[i][1];
            res[first] += bookings[i][2];
            if (last < n)
                res[last] -= bookings[i][2];
        }
        for (int i = 1; i < n; i++)
        {
            res[i] += res[i - 1];
        }
        return res;
    }
};