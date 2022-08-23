#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> m;
        int rabbits = 0; // minimum possible rabbits;
        for (auto rabbit : answers)
        {
            if (m.find(rabbit) != m.end())
            {
                int quota = m[rabbit];
                quota--;
                if (quota == 0)
                {
                    auto it = m.find(rabbit);
                    m.erase(it);
                }
                else
                {
                    m[rabbit] = quota;
                }
            }
            else
            {
                rabbits += rabbit;
                rabbits++;

                if (rabbit != 0)
                {
                    m[rabbit] = rabbit;
                }
            }
        }
        return rabbits;
    }
};