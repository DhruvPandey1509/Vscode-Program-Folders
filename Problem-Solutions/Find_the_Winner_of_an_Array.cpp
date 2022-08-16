#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int win = 0, j = 1;

        int cwin = 0;

        while (j < arr.size() and k != cwin)
        {
            if (arr[j] < arr[win])
            {
                cwin++;
            }
            else
            {
                cwin = 1;
                win = j;
            }
            j++;
        }

        return arr[win];
    }
};