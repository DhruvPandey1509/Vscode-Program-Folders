#include "bits/stdc++.h"
using namespace std;

// Let's check a simple example: [5,2,1].
// The ideal case is that we can use all milestones: 5 + 2 + 1 = 8.
// But the answer to this problem is 7, why?
// Because let's check the solution sequence: 5 1 5 2 5 1 5 (7 steps).
// To find out why this sequence is working let's remove max number form the sum: 8 - 5 = 3.
// Which means that we can have 3 alternation with 5: 5 1 5 2 5 1 (3 * 2 = 6 steps).
// The last one step is added because we can use 5 again after 1 (in total: 3 * 2 + 1 = 7).
// Otherwise if the sum of sum - maxel >= maxel it means that we can use all milestones and return answer.
class Solution
{
public:
    long long numberOfWeeks(vector<int> &milestones)
    {
        long long int maxNum = *max_element(milestones.begin(), milestones.end());
        long long int sum = 0;
        sum = accumulate(milestones.begin(), milestones.end(), sum);

        long long int remainSum = sum - maxNum;

        if (maxNum <= remainSum)
            return sum;

        return remainSum * 2 + 1;
    }
};