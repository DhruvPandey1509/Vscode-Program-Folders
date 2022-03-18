#include "bits/stdc++.h"
using namespace std;
class Solution
{
    struct node
    {
        int no;
        int freq;
        node(int a, int b) // Constructor for value initialization for each node
        {
            no = a;
            freq = b;
        }
    };

    struct compare
    { // Maintains MAX-HEAP based on frequency
        bool operator()(node const &a, node const &b)
        {
            return a.freq < b.freq;
        }
    };

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m; // key = Number   Value = Frequency

        // Step 1 :- Store frequency of all element in map
        for (auto ele : nums)
        {
            m[ele] += 1;
        }

        // Step 2 :- Now build a Heap
        priority_queue<node, vector<node>, compare> heap; // Compare defines a max Heap based on frequency
        for (auto i : m)
        {
            heap.push(node(i.first, i.second));
        }

        vector<int> res; // Stores top-K elements
        // Step3 :- Pop top-K elements and store the numbers in ans vector

        while (k--)
        {
            node temp = heap.top();
            heap.pop();
            res.push_back(temp.no);
        }

        return res;
    }
};