#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;

        int srow = 0; // start row
        int scol = 0; // start col

        int erow = row; // end row
        int ecol = col; // end col

        vector<int> res;

        int c = 0;
        int total = (row + 1) * (col + 1);

        while (c < total)
        {
            for (int i = scol; c < total && i <= ecol; i++)
            {
                res.push_back(matrix[srow][i]);
                c++;
            }
            srow++;

            for (int i = srow; c < total && i <= erow; i++)
            {
                res.push_back(matrix[i][ecol]);
                c++;
            }
            ecol--;

            for (int i = ecol; c < total && i >= scol; i--)
            {
                res.push_back(matrix[erow][i]);
                c++;
            }
            erow--;

            for (int i = erow; c < total && i >= srow; i--)
            {
                res.push_back(matrix[i][scol]);
                c++;
            }
            scol++;
        }

        return res;
    }
};