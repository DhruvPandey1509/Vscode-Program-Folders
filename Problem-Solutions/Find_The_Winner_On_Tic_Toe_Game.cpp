#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        vector<vector<char>> v(3, vector<char>(3));

        char val = 'x';
        for (auto m : moves)
        {
            v[m[0]][m[1]] = val;
            val = val == 'x' ? 'o' : 'x';
        }

        for (int i = 0; i < 3; i++)
        {
            // check Row
            if (v[i][0] == 'x' and v[i][1] == 'x' and v[i][2] == 'x')
                return "A";
            if (v[i][0] == 'o' and v[i][1] == 'o' and v[i][2] == 'o')
                return "B";

            // check coloumn
            if (v[0][i] == 'x' and v[1][i] == 'x' and v[2][i] == 'x')
                return "A";
            if (v[0][i] == 'o' and v[1][i] == 'o' and v[2][i] == 'o')
                return "B";
        }

        // check diagonal
        if (v[0][0] == 'x' and v[1][1] == 'x' and v[2][2] == 'x')
            return "A";
        if (v[0][2] == 'x' and v[1][1] == 'x' and v[2][0] == 'x')
            return "A";
        if (v[0][0] == 'o' and v[1][1] == 'o' and v[2][2] == 'o')
            return "B";
        if (v[0][2] == 'o' and v[1][1] == 'o' and v[2][0] == 'o')
            return "B";

        if (moves.size() == 9)
            return "Draw";

        return "Pending";
    }
};