#include "bits/stdc++.h"
using namespace std;

// Condition for three points/coordinates (x0, y0), (x1, y1), (x, y) to be collinear is :
// (x - x0) (y1 - y0) == (y - y0) (x1 - x0)

// Reason: Slope for a line through 2 points (x0, y0), (x1, y1) is (y1 - y0)/(x1 - x0) and Slope for a line through other 2 points (x, y), (x0, y0) is (y - y0)/(x- x0).
// Now for these 3 points[(x0, y0), (x1, y1), (x, y)] to be collinear the slopes must be equal i.e,
// (y1 - y0)/(x1 - x0) = (y - y0)/(x- x0)
// or, (x - x0) (y1 - y0) = (y - y0) (x1 - x0)
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int rows = coordinates.size();
        if (rows == 2)
            return true;

        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];

        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];

        int dx = x1 - x0, dy = y1 - y0;

        for (int i = 2; i < rows; i++)
        {
            int x = coordinates[i][0], y = coordinates[i][1];

            if (dx * (y - y1) != dy * (x - x1))
                return false;
        }

        return true;
    }
};