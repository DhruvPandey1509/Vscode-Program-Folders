#include "bits/stdc++.h"
using namespace std;

bool isPrime(int num)
{
    int count = 0;
    if (num == 0 || num == 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void computePrime(vector<int> &prime)
{
    int next_prime = INT_MAX;
    for (int i = 10e5; i >= 0; i--)
    {
        if (isPrime(i))
        {
            next_prime = i;
        }
        prime[i] = next_prime;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<int> prime(10e5 + 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    computePrime(prime);
    vector<int> row(n, 0), col(m, 0);
    int res = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            row[i] += prime[v[i][j]] - v[i][j];
            col[j] += prime[v[i][j]] - v[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        res = min(res, row[i]);
    }

    for (int j = 0; j < m; j++)
    {
        res = min(res, col[j]);
    }

    cout << res << endl;
    return 0;
}