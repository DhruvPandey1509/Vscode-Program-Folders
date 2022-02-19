#include "bits/stdc++.h"
using namespace std;
//mx consecutive ones in an array containing 0's and 1's
//can convert at-max k 0's to 1's to get the max consecutive one's count
int main()
{
    int n, k; //k = no. of zeroes that can be converted to 1 for getting max consecutive number in the given array
    cin >> n >> k;
    vector<int> a(n);

    for (auto &i : a)
    {
        cin >> i;
    }
    int zeroCount = 0, i = 0, ans = 0;

    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            zeroCount++;
        }
        while (zeroCount > k)
        {
            if (a[i] == 0)
            {
                zeroCount--;
            }
            i++;
        }

        ans = max(ans, j - i + 1);
    }
    cout << ans << endl;

    return 0;
}
/*
Input
5 2
1 1 0 0 1
Output
5

Input
19 3
0 0 1 1 0 0 1 1 1 0 1 1 0 0 0 1 1 1 1
Output
10
*/