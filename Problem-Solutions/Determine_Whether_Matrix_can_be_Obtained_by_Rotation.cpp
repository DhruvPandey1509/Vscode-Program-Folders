#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        int l = 4;

        while (l--)
        {
            if (mat == target)
                return true;

            // transpose of the matrix;
            for (int i = 0; i < rows; i++)
            {
                for (int j = i; j < cols; j++)
                {
                    swap(mat[i][j], mat[j][i]);
                }
            }

            // row-wise swap or row wise reverse;
            for (int i = 0; i < rows; i++)
            {
                reverse(mat[i].begin(), mat[i].end());
            }
        }

        return false;
    }
};