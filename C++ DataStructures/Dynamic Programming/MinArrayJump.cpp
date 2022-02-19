// Min jump required to reach the end of the array
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minJump(vector<int> a, int n, vector<int> dp, int i = 0)
{
    if (i == n - 1)
    {
        return 0;
    }

    if (i >= n)
    {
        return INT_MAX;
    }

    // recursive case
    if (dp[i] != 0)
    {
        return dp[i];
    }

    // assume
    int steps = INT_MAX;
    int maxJump = a[i];

    for (int jump = 1; jump <= maxJump; jump++)
    {
        int nextIdx = i + jump;
        int subprob = minJump(a, n, dp, nextIdx);
        if (subprob != INT_MAX)
        {
            steps = min(steps, subprob + 1);
        }
    }

    return dp[i] = steps;
}

int main()
{
    vector<int> a{3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    int n = a.size();

    // create an array for dp
    vector<int> dp(n + 1, 0);

    cout << minJump(a, n, dp, 0) << endl;

    return 0;
}