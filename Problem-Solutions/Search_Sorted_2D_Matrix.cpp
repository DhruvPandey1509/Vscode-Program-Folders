#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int row = matrix.size(), col = matrix[0].size();
        int r = -1;

        // Iterative way to find the row and similary we then can find target
        //  for(int i = 0; i < row; i++)
        //  {
        //      if(matrix[i][0] <= target && matrix[i][col-1] >= target)
        //      {
        //          r = i;
        //          break;
        //      }
        //  }

        // Optimized solution using Binary Search
        int lo = 0, hi = row - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid][0] <= target && matrix[mid][col - 1] >= target)
            {
                r = mid;
                break;
            }
            else if (matrix[mid][0] > target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        if (r == -1)
        {
            return false;
        }

        lo = 0, hi = col - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (matrix[r][mid] == target)
            {
                return true;
            }
            else if (matrix[r][mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return false;
    }
};