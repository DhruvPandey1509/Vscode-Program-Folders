#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {

        unordered_map<int, int> m;
        int min_num = INT_MAX;
        for (int i = 0; i < cards.size(); i++)
        {
            if (m.find(cards[i]) == m.end())
            {
                m[cards[i]] = i;
            }
            else
            {
                min_num = min(min_num, i - m[cards[i]] + 1);
                m[cards[i]] = i; // storing the last occurrence of the number
            }
        }

        if (min_num == INT_MAX)
            return -1;

        return min_num;
    }
};