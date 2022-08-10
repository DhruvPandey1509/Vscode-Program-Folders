#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int m = flowerbed.size();

        for (int i = 0; i < m; i++)
        {
            if (flowerbed[i] == 0)
            {
                int x = (i == 0) || flowerbed[i - 1] == 0 ? 0 : 1;
                int y = (i == m - 1) || flowerbed[i + 1] == 0 ? 0 : 1;

                if (x == 0 and y == 0)
                {
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }
        return n <= 0;
    }
};