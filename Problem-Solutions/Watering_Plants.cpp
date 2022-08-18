#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int steps = 0;
        int cap = capacity;
        for (int i = 0; i < plants.size(); i++)
        {
            if (cap < plants[i])
            {
                cap = capacity;
                steps += 2 * i + 1;
            }
            else
            {
                steps++;
            }
            cap -= plants[i];
        }

        return steps;
    }
};