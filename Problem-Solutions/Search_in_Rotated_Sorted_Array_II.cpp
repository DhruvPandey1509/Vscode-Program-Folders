#include "bits/stdc++.h"
using namespace std;

// Way 1
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {

        vector<int>::iterator it;
        it = find(nums.begin(), nums.end(), target);
        return (it != nums.end());
    }
};