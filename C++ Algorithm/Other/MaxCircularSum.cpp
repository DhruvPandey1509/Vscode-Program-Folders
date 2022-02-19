#include "bits/stdc++.h"
using namespace std;

int kadane(int *a, int n)
{
    int currSum = 0;
    int maxSum = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        if (currSum < 0)
        {
            currSum = 0;
        }

        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main()
{
    int a[] = {4, -4, 6, -6, 10, -11, 12};
    int n = sizeof(a) / sizeof(a[0]);

    int nonWrapSum = kadane(a, n - 1);

//finding wrap Sum
    int totalSum = 0;
//storing total sum of the elements and reversing the sign of the elements in the array
    for (int i = 0; i < n; i++)
    {
        totalSum += a[i];
        a[i] = -a[i];
    }

//applying kadanes on the reversed sign elements and finding its max sum and adding it to the total sum to get wrap sum.

    int wrapSum = totalSum + kadane(a, n - 1);

// printing the greater of wrapsuma and nonWrapSum
    cout << max(nonWrapSum, wrapSum) << endl;

    return 0;
}