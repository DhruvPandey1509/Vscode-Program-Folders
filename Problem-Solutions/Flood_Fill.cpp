#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> addRow = {-1, 0, +1, 0};
    vector<int> addCol = {0, -1, 0, +1};
    int initColor;
    void dfs(vector<vector<int>> &res, vector<vector<int>> &image, int row, int col, int color)
    {
        res[row][col] = color; // adding new color
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int r = row + addRow[i];
            int c = col + addCol[i];
            // checking if the cell we are picking is of same color and in res matrix that cell is not previously colored(indicating visited) and then all the boundary countions first to not encounter any segmentation faut error.
            if (r >= 0 && r < n && c >= 0 && c < m && image[r][c] == initColor && res[r][c] != color)
            {
                dfs(res, image, r, c, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        initColor = image[sr][sc];
        vector<vector<int>> res = image;

        dfs(res, image, sr, sc, color);
        return res;
    }
};