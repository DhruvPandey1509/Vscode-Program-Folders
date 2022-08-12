#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {

        if (tomatoSlices == 0 and cheeseSlices == 0)
            return {0, 0};
        if (tomatoSlices % 2 != 0)
            return {};

        if (tomatoSlices <= cheeseSlices)
            return {};
        if ((tomatoSlices - (2 * cheeseSlices)) % 2 != 0)
            return {};

        int x = (tomatoSlices - (2 * cheeseSlices)) / 2;
        if (x < 0)
            return {};

        int y = cheeseSlices - x;
        if (y < 0)
            return {};

        return {x, y};
    }
};