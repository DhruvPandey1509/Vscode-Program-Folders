#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {

        int rows = rowSum.size();
        int cols = colSum.size();

        vector<vector<int>> res(rows, vector<int>(cols, 0));
        int i = 0, j = 0;

        while (i < rows and j < cols)
        {
            if (rowSum[i] < colSum[j])
            {
                res[i][j] = rowSum[i];
                colSum[j] -= rowSum[i];
                rowSum[i++] = 0;
            }
            else
            {
                res[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                colSum[j++] = 0;
            }
        }

        return res;
    }
};
