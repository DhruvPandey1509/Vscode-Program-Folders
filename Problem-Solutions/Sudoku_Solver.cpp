#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

    bool solve(vector<vector<char>> &board)
    {

        // no need base case as when u find all are filled, then no need further rec calls
        // so loops stop making rec calls when all are  filled
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    // 1st empty found
                    for (char c = '1'; c <= '9'; c++)
                    {
                        // as ASCII Take cares of order
                        // now set the val in board and see further board is solvable or not

                        // if its not even valid then u should not place that val, its rule offence
                        if (isValid(c, board, i, j))
                        {
                            board[i][j] = c;

                            if (solve(board) == true)
                            {
                                // dont make further rec calls - for that simply return
                                return true; // till main it will go
                            }

                            // The further board is not solvable
                            //  so now erase prev vals
                            // backtrack
                            board[i][j] = '.'; // from c to . empty cell
                        }
                    }
                    return false; // when no val from 1 to 9 fits in
                }
            }
        }

        return true; // when all cells filled - we found 1 sol
    }

    bool isValid(char c, vector<vector<char>> &board, int row, int col)
    {
        for (int i = 0; i < 9; i++)
        {
            
            //to check whole row
            if (board[row][i] == c)
                return false;
            //to check whole column
            if (board[i][col] == c)
                return false;

            //to check the particular grid where the cell is lying. Note:- whole grind contains :- 9 ---   3X3 smaller grids so we are checking on of those 9 grids that contains the cell [row][col] 
            int rd = 3 * (row / 3) + i / 3; // i/3 - as we want a increment for every 3 iter - to go next row
            int cd = 3 * (col / 3) + i % 3; // i%3 - as we want a inc for every time but a reset to 0 for every 3 times after
            if (board[rd][cd] == c)
                return false;
        }
        return true;
    }
};