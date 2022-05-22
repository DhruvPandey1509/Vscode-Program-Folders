#include "bits/stdc++.h"
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void transpose(vector<vector<int>> &v, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            swap(&v[i][j], &v[j][i]);
        }
        cout << endl;
    }
}
void cr(vector<vector<int>> &v, int row, int col) // column wise reverse (Clockwise Rotate)
{
    int k = 0;

    for (int j = col - 1; j >= col / 2 && k < j; j--)
    {
        for (int i = 0; i < row; i++)
        {
            swap(&v[i][k], &v[i][j]);
        }
        k++;
    }
}
void rr(vector<vector<int>> &v, int row, int col) // row-wise reverse (Anticlockwise Rotate)
{
    int k = 0;

    for (int i = row - 1; i >= row / 2; i--)
    {
        for (int j = 0; j < col; j++)
        {
            swap(&v[i][j], &v[k][j]);
        }
        k++;
    }
}
int main()
{
    vector<vector<int>> v = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int row = v.size();
    int col = v[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    transpose(v, row, col);
    rr(v, row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}