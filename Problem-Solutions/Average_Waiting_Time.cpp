#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double n = customers.size();
        double time = customers[0][1];
        int finish = customers[0][0] + customers[0][1];
        for (int i = 1; i < customers.size(); i++)
        {
            if (finish >= customers[i][0])
            {
                time += customers[i][1] + (finish - customers[i][0]);
                finish += customers[i][1];
            }
            else
            {
                time += customers[i][1];
                finish = customers[i][0] + customers[i][1];
            }
        }
        return ((time) / (n));
    }
};