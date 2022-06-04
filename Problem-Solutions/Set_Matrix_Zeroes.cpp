#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> row;
        vector<int> col;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for (int i = 0; i < row.size(); i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[row[i]][j] = 0;
            }
        }

        for (int i = 0; i < col.size(); i++)
        {
            for (int j = 0; j < rows; j++)
            {
                matrix[j][col[i]] = 0;
            }
        }
    }
};