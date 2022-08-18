#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        if (colors.size() < 3)
            return false;

        if (colors.size() == 3)
        {
            return colors == "AAA";
        }

        int a = 0, b = 0;
        for (int i = 1; i < colors.size() - 1; i++)
        {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A')
                a++;
            else if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B')
                b++;
        }

        if (b >= a)
            return false;

        return true;
    }
};