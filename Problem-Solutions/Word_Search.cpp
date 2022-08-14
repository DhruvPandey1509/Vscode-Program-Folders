#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    const static int R = 4;
    vector<vector<int>> direction = {{-1, 0},
                                     {1, 0},
                                     {0, -1},
                                     {0, 1}};
    bool wordFound = false;
    bool exist(vector<vector<char>> &board, string word)
    {

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                // finding first letter
                if (board[i][j] == word[0])
                {
                    board[i][j] = '.';
                    findNextLetter(board, word, i, j, 1);
                    board[i][j] = word[0]; // backtracking
                }
            }
        }

        return wordFound;
    }

    void findNextLetter(vector<vector<char>> &board, string word, int row, int col, int index)
    {
        if (index == word.size())
            wordFound = true;

        else if (index < word.size() and !wordFound)
        {
            // search in all 4 direction up down left right of current cell of board
            for (int i = 0; i < R; i++)
            {
                int r = row + direction[i][0];
                int c = col + direction[i][1];

                if (r >= 0 and c >= 0 and r < board.size() and c < board[0].size())
                {
                    if (board[r][c] == word[index])
                    {
                        board[r][c] = '.';
                        findNextLetter(board, word, r, c, index + 1);
                        board[r][c] = word[index];
                    }
                }
            }
        }
    }
};