#include "bits/stdc++.h"
using namespace std;

// extension * p = reflection * q
// here we can take extension = q and reflection = p;
// extension = even  reflection = odd   receptor = 0
// extension = odd reflection = even   receptor = 2
// extension = odd  reflection = odd   receptor = 1
class Solution
{
public:
    int mirrorReflection(int p, int q)
    {

        int ext = q, ref = p;

        // loop for reducing ext and ref if both are even to make it suitable to             apply our 3 case
        while (ext % 2 == 0 and ref % 2 == 0)
        {
            ext /= 2;
            ref /= 2;
        }

        if (ext % 2 == 0 and ref % 2 != 0)
        {
            return 0;
        }

        else if (ext % 2 != 0 and ref % 2 == 0)
        {
            return 2;
        }

        return 1;
    }
};