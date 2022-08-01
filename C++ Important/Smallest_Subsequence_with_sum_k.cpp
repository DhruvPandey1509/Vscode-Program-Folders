#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> v, int k)
{
    int count = 0;
    int sum = 0;

    priority_queue<int> p;
    for (int i = 0; i < v.size(); i++)
    {
        p.push(v[i]);
    }

    while (!p.empty())
    {
        sum += p.top();
        p.pop();

        count++;

        if (sum >= k)
            break;
    }

    if (sum < k)
        return -1;

    return count;
}

int main()
{
    vector<int> v = {1, 1, 3, 2, 8};
    int k = 1;

    cout << solution(v, k) << endl;

    return 0;
}