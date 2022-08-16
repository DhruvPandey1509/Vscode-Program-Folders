#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();

        // solving for upper right triangle
        for (int i = 0; i < col; i++)
        {
            vector<int> v;

            int p = 0;
            int q = i;

            while (p < row and q < col)
            {
                v.push_back(mat[p][q]);
                p++;
                q++;
            }

            sort(v.begin(), v.end());

            // placing the sorted diagonal elements back in the matrix
            p = 0;
            q = i;
            int j = 0;
            while (p < row and q < col)
            {
                mat[p][q] = v[j];
                p++;
                q++;
                j++;
            }
        }
        // solving lower left triangle
        for (int i = 1; i < row; i++)
        {
            vector<int> v;

            int p = i;
            int q = 0;
            while (p < row and q < col)
            {
                v.push_back(mat[p][q]);
                p++;
                q++;
            }
            sort(v.begin(), v.end());
            // placing the sorted diagonal elements back in the matrix
            p = i;
            q = 0;
            int j = 0;
            while (p < row and q < col)
            {
                mat[p][q] = v[j];
                p++;
                q++;
                j++;
            }
        }

        return mat;
    }
};