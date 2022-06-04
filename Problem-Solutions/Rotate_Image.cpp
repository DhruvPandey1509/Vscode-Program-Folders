#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void transpose(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>> &matrix)
    {

        transpose(matrix);

        int n = matrix.size();
        int k = n - 1;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n / 2; c++)
            {
                swap(matrix[r][c], matrix[r][k]);
                k--;
            }
            k = n - 1;
        }
    }
};