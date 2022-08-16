#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> res;
        for (int i = 0; i < matrix.size(); i++)
        {
            int min_in_row = matrix[i][0];
            int index = 0;

            // finding minimum in row
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] < min_in_row)
                {
                    min_in_row = matrix[i][j];
                    index = j; // storing the index of column to check whether it is max in its col
                }
            }

            bool flag = true;
            // cheking if min of row is max in its col
            for (int j = 0; j < matrix.size(); j++)
            {
                if (min_in_row < matrix[j][index])
                    flag = false;
            }

            // if it is push it in our res vector
            if (flag)
                res.push_back(min_in_row);
        }

        return res;
    }
};