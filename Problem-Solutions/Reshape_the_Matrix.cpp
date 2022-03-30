#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {

        int row = mat.size();
        int col = mat[0].size();
        if (r * c != row * col)
        {
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c));
        vector<int> v(r * c);

        //         Loop to convert 2d matrix to 1d matrix;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                v[i * col + j] = mat[i][j];
            }
        }
        //         Reshaping the matrix;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                res[i][j] = v[i * c + j];
            }
        }

        return res;
    }
};