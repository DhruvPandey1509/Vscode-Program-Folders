#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> v(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int count = 0;
                if (j + 1 < cols && board[i][j + 1] == 1)
                {
                    count++;
                }
                if (i + 1 < rows && board[i + 1][j] == 1)
                {
                    count++;
                }
                if (i - 1 >= 0 && board[i - 1][j] == 1)
                {
                    count++;
                }
                if (j - 1 >= 0 && board[i][j - 1] == 1)
                {
                    count++;
                }
                if (i + 1 < rows && j + 1 < cols && board[i + 1][j + 1] == 1)
                {
                    count++;
                }
                if (i + 1 < rows && j - 1 >= 0 && board[i + 1][j - 1] == 1)
                {
                    count++;
                }
                if (j + 1 < cols && i - 1 >= 0 && board[i - 1][j + 1] == 1)
                {
                    count++;
                }
                if (j - 1 >= 0 && i - 1 >= 0 && board[i - 1][j - 1] == 1)
                {
                    count++;
                }
                if (board[i][j] == 1 && count == 2 || count == 3)
                {
                    v[i][j] = 1;
                }
                if (board[i][j] == 0 && count == 3)
                {
                    v[i][j] = 1;
                }
            }
        }

        board.clear();
        board = v;
        v.clear();
    }
};