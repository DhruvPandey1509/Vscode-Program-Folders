#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
/* sum of three elements at distinct position is zero. Print all the possible combinations if so. */
int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int lo = i + 1, hi = n - 1;
        while (lo < hi)
        {
            int current = a[i] + a[lo] + a[hi];
            if (current == 0)
            {
                cout << a[i] << " " << a[lo] << " " << a[hi] << endl;
                lo++;
            }
            else if (current < 0)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }
    }

    return 0;
}
