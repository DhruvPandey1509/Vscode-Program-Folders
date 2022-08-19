/*
Intriguing problem and while we might be tempted to solve it in quadratic time (counting all the elements to the left and to the right of each cell with their distances from it), we can of course do better.

If we think for example about the string "001011", we will see that the first cell needs 2 moves for the firsts '1', 4 for the second '1' and 5 moves for the last '1', so 11 moves in total; the second cell will require only 8 moves in total, since we moved closer to all 3 existing '1' to the right of it and so on. Only once we pass a '1' we will start reducing the total cost of the previous cell in smaller increment: after we reach the third cell, which is itself a 1 and will cost us 8 - 3 == 5 moves to fill, we will start decreasing the cost of moving the balls to the right by 2 at each step.

We can have specular logic running for the left side and we are mostly done.

Now, to translate all this elucubrations into code, we will start declaring a few support variables:

left and leftSum will store the number of elements on the left of the current cell and the total cost to move them in position, all initialised to 0;
specularly, right and rightSum will store the number of balls and their cost to be moved in the current cell - again set to 0 initially;
len will store the length of boxes;
res will be our accumulator variable, set to be already of the proper size (len) to avoid reallocations.
We will then compute right and rightSum, parsing boxes from the right with i and:

increasing right by 1 when we meet a '1';
increasing rightSum by right, as explained above.
Now, with this information readied, we can go and compute each cell of res, again using i, this time from the left and:

set currIsOne to be 1 when the current character is a '1', 0 otherwise;
specularly to the above move, decreasing rightSum by right;
decreasing right by currIsOne;
writing the sum of leftSum and rightSum into the ith cell of res;
again, specularly to the first loop, increasing left by currIsOne;
increasing leftSum by left, as explained above.
Once done, we can just return res :)
*/

#include "bits/stdc++.h"
using namespace std;

// Minimum Number of Operations to Move All Balls to Each Box

// Way 1  T.C = O(n*k) where k = size of set and n = length of string boxes
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {

        set<int> s;
        vector<int> res;

        for (int i = 0; i < boxes.size(); i++)
        {
            if (boxes[i] == '1')
            {
                s.insert(i);
            }
        }

        for (int i = 0; i < boxes.size(); i++)
        {
            int sum = 0;
            for (auto &j : s)
            {
                sum += abs(j - i);
            }
            res.push_back(sum);
        }
        return res;
    }
};

// Way 2 T.C = O(n)

class Solution1
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> res;
        int right = 0, rightSum = 0, left = 0, leftSum = 0;

        for (int i = boxes.size() - 1; i >= 0; i--)
        {
            right += 0;
            if (boxes[i] == '1')
            {
                right += 1;
            }
            rightSum += right;
        }

        for (int i = 0, curr; i < boxes.size(); i++)
        {
            curr = 0;
            if (boxes[i] == '1')
            {
                curr = 1;
            }

            rightSum -= right;
            right -= curr;

            res.push_back(leftSum + rightSum);

            left += curr;
            leftSum += left;
        }

        return res;
    }
};