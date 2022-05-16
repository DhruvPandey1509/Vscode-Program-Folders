#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // You need to complete this function
    // avoid space at the starting of the string in "move disk....."
    long long count = 0;
    long long toh(int n, int from, int to, int aux)
    {
        if (n > 0)
        {
            toh(n - 1, from, aux, to);
            cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
            count++;
            toh(n - 1, aux, to, from);
        }

        return count;
    }
};