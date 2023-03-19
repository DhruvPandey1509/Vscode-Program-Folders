#include "bits/stdc++.h"
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<ll> positive, negative;
    ll totalSum = 0;
    int zero = 0;
    ll temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp < 0)
        {
            negative.push_back(-temp);
        }
        else if (temp == 0)
        {
            zero++;
        }
        else
        {
            positive.push_back(temp);
        }
    }
    sort(positive.begin(), positive.end());
    for (int i = 0; i < positive.size(); i++)
    {
        totalSum += positive[i];
    }

    if (negative.size() % 2) // odd number of negative elements
    {
        if (zero == 0)
        {
            sort(negative.begin(), negative.end());
            for (int i = 0; i < negative.size(); i++)
            {
                totalSum += negative[i];
            }
            if (positive.size())
            {
                totalSum -= 2 * min(positive[0], negative[0]);
            }
            else
            {
                totalSum -= 2 * negative[0];
            }
        }
        else
        {
            for (int i = 0; i < negative.size(); i++)
            {
                totalSum += negative[i];
            }
        }
    }
    else // even number of negative elements present
    {
        for (int i = 0; i < negative.size(); i++)
        {
            totalSum += negative[i];
        }
    }
    cout << totalSum << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}