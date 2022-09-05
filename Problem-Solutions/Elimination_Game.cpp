#include "bits/stdc++.h"
using namespace std;

// INTUITION: After every move, the number of elements will be halved
// Now two for each type of move:-
//(i) Elimination from left to right: the firstmost element is bound to be removed, so we have to shift our starting pointer to the right (by no. of steps)
//(ii) Elimination from right to left: the starting element will be removed only if the number of elements left is odd. Only in that case our starting pointer would be shifted to the right otherwise not.

// Now how do we decide the number of steps by which the starting pointer needs to be shifted?
// If we notice properly, the no. of elements getting eliminated each time is n/2. So the step(difference)
// between remaining elements increases by x2 each time.
// So the no. of step/difference doubles with every move that we perform.
class Solution
{
public:
    int lastRemaining(int n)
    {
        int left_to_right = true;
        int st = 1;
        int step_size = 1;

        while (n > 1)
        {
            if (left_to_right)
                st += step_size;
            else
                st += n & 1 ? step_size : 0;

            step_size *= 2;
            n /= 2;
            left_to_right = !left_to_right;
        }

        return st;
    }
};