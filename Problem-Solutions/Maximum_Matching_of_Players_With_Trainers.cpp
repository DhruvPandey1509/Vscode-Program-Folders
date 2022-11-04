#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int p = players.size() - 1;
        int t = trainers.size() - 1;
        int count = 0;
        while (p >= 0 and t >= 0)
        {
            if (players[p] <= trainers[t])
            {
                count++;
                p--;
                t--;
            }
            else
            {
                p--;
            }
        }

        return count;
    }
};