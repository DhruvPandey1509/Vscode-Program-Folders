#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double minDegree = 6 * minutes;
        if (hour == 12)
            hour = 0;
        double hourDegree = (hour * 30 + (minDegree / 12.0));
        double angle1 = abs(minDegree - hourDegree);
        double angle2 = abs(360.0 - angle1);
        return min(angle1, angle2);
    }
};
