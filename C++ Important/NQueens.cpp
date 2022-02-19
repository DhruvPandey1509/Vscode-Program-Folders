#include<iostream>
using namespace std;

bool isSafe(int **a, int x, int y, int n)//x = current row, y = current coloumn, n = size of row and coloumn
{
    // checking for queen in the same coloum
    for(int row = 0 ; row < x ; row++)
    {
        if(a[row][y] == 1)
        {
            return false;
        }
    }

    // checking for queen in the left upper diagnol for the current position of queen
    int row = x;
    int col = y;

    while(row >= 0 && col >= 0)
    {
        if(a[row][col] == 1)
        {
            return false;
        }

        row--, col--;
    }
    // checking for queen in the right upper diagnol for the current position of queen
    row = x;
    col = y;

    while(row >= 0 && col < n)
    {
        if(a[row][col] == 1)
        {
            return false;
        }

        row--, col++;
    } 

    return true;

}

bool nQueen(int** a, int x, int n) //x = current row, n = size
{
    if(x >= n)
    {
        return true;
    }

    for(int col = 0 ; col < n ; col++)
    {
        if(isSafe(a, x, col, n))
        {
            a[x][col] = 1;

            if(nQueen(a,x+1,n))//jumping to next row and checking for it
            {
                return true;
            }
            else
            a[x][col] = 0;
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    if (nQueen(a, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;

    return 0;
}