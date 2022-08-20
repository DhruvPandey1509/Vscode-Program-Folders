#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {

        int st = 0, len = 1, count = 0;
        for (int i = 0; i < grades.size(); i++)
        {
            if (i - st + 1 == len)
            {
                count++;
                len++;
                st = i + 1;
            }
        }

        return count;
    }
};
/*
It's a tricky question. It doesn't matter if the array is sorted or not.
Also you dont have to keep track of the sum. We are basically picking one element more everytime,
assuming it's sorted in ascending order we will get the sum greater everytime.
So if you observe carefully we dont need to track the sum of a group,
which means you don't have to sort the array . You can just count how many groups you can create.
*/