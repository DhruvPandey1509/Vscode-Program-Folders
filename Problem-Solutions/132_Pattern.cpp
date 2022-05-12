#include "bits/stdc++.h"
using namespace std;

// 1.)Stack of pair where first value is the current value in the array and the second value is the minimun value till now in the array excluding the current value.
// 2.)We are using monotonically decreasing array.
// 3.)If the current array element is greater then the top of the element in the array we will keep popping the top element until the element at the top of stack is greater then the current element of the array.
// 4.)If our stack is not empty and the current element of the array is smaller then the element at the top of the stack and also greater then the minimum element till now of the array that is represented by the second value in the top of the stack then we can say that 132 pattern is forming so we will return true.
// 5.)We will keep iterating till the end of the array.
// 6.) If none of our condtions are met then after iterating whole array we break out of our loop and return false.

class Solution
{
public:
    bool find132pattern(vector<int> &a)
    {
        stack<pair<int, int>> st; // monotonic decreasing stack
        int curr_min = a[0];

        st.push({a[0], curr_min});

        for (int i = 1; i < a.size(); i++)
        {
            while (!st.empty() and a[i] >= st.top().first)
            {
                st.pop();
            }
            if (!st.empty() and a[i] < st.top().first and a[i] > st.top().second)
            {
                return true;
            }

            curr_min = min(curr_min, a[i - 1]);
            st.push({a[i], curr_min});
        }
        return false;
    }
};