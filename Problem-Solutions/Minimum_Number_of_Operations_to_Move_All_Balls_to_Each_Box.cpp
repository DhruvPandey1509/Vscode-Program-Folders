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