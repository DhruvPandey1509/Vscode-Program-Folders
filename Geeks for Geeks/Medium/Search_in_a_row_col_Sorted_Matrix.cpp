#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> v, int n, int m, int key)
    {
        int row = 0;
        int col = m - 1;
        while (row < n && col >= 0)
        {
            if (key < v[row][col])
            {
                col--;
            }
            else if (key > v[row][col])
            {
                row++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};