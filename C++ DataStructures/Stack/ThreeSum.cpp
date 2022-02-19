#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
/* sum of three elements at distinct position is equal to the given value.
 Print all the possible combinations if so. */
int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> a(n);
   for(auto &i : a)
   {
       cin>>i;
   }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int lo = i + 1, hi = n - 1;
        while (lo < hi)
        {
            int current = a[i] + a[lo] + a[hi];
            if(current == target)
            {
                cout << "true" << endl;
                return 1;
            }
            else if(current < target)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }
    }
    cout << "false" << endl;
    return 0;
}