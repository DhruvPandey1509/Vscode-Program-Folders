#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> m;
        int rounds = 0;
        for (auto i : tasks)
        {
            m[i]++;
        }

        for (auto i : m)
        {
            if (i.second < 2)
                return -1;
            else
            {
                if (i.second % 3 == 0)
                {
                    rounds += (i.second / 3);
                }
                else if (i.second % 3 == 2)
                {
                    rounds += (i.second / 3 + 1);
                }
                else if (i.second % 3 == 1)
                {
                    rounds += (i.second / 3 - 1 + 2);
                }
            }
        }
        return rounds;
    }
};
