#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        vector<vector<int>> matrix(n, vector<int>(n));
        int row = n - 1;
        int col = n - 1;

        int sRow = 0;
        int sCol = 0;

        int eRow = row;
        int eCol = col;

        int val = 1;

        int total = n * n;
        int c = 0;

        while (c < total)
        {
            for (int i = sCol; c < total && i <= eCol; i++)
            {
                matrix[sRow][i] = val;
                val++;
                c++;
            }
            sRow++;

            for (int i = sRow; c < total && i <= eRow; i++)
            {
                matrix[i][eCol] = val;
                val++;
                c++;
            }
            eCol--;

            for (int i = eCol; c < total && i >= sCol; i--)
            {
                matrix[eRow][i] = val;
                val++;
                c++;
            }
            eRow--;

            for (int i = eRow; c < total && i >= sRow; i--)
            {
                matrix[i][sCol] = val;
                val++;
                c++;
            }
            sCol++;
        }

        return matrix;
    }
};