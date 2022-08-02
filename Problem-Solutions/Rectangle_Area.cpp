#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);

        if (ax1 <= bx2 and bx1 <= ax2 and ay1 <= by2 and by1 <= ay2)
        {
            int a = min(ax2, bx2) - max(ax1, bx1);
            int b = min(ay2, by2) - max(ay1, by1);
            int area3 = a * b;
            return area1 + area2 - area3;
        }

        return area1 + area2;
    }
};