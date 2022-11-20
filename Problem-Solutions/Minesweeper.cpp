#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int countMines(vector<vector<char>> &board, int i, int j)
    {
        int count = 0;
        for (int r = -1; r <= 1; r++)
        {
            for (int c = -1; c <= 1; c++)
            {
                int row = i + r;
                int col = j + c;
                if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size())
                {
                    if (board[row][col] == 'M')
                        count++;
                }
            }
        }

        return count;
    }
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        // checking for the boundary cases
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;

        // if the cell is already visited(it will be marked B if no adjacent mine) or count of mine if its adjacent
        if (board[i][j] == 'B' || (board[i][j] >= '1' && board[i][j] <= '9'))
            return;
        int count = countMines(board, i, j); // counting the number of adjacent mines to current cell
        if (count > 0)
        {
            board[i][j] = '0' + count;
            return;
        }
        // if no mines in adjacent cells
        board[i][j] = 'B';

        for (int r = -1; r <= 1; r++)
        {
            for (int c = -1; c <= 1; c++)
            {
                dfs(board, i + r, j + c);
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int i = click[0];
        int j = click[1];
        if (board[i][j] == 'M')
        {
            board[i][j] = 'X';
            return board;
        }
        else
        {
            dfs(board, i, j);
            return board;
        }
    }
};