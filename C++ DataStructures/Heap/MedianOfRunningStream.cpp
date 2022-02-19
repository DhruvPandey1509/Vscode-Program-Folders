#include "bits/stdc++.h"
using namespace std;

int main()
{
    priority_queue<float, vector<float>> q1;                 //maxHeap    LeftHalf
    priority_queue<float, vector<float>, greater<float>> q2; //minHeap     RightHalf

    bool cond = true;
    int num = 0;
    float med = 0;
    while (num != -1)
    {
        cin >> num;

        //leftHeap size is greater
        if (q1.size() > q2.size())
        {
            if (num < med)
            {
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
            }
            else
            {
                q2.push(num);
            }

            med = (q1.top() + q2.top()) / 2.0;
        }

        //both heap have same size.
        else if (q1.size() == q2.size())
        {
            if (num < med)
            {
                q1.push(num);
                med = q1.top();
            }
            else
            {
                q2.push(num);
                med = q2.top();
            }
        }

        //rightHeap is greater
        else
        {
            if (num > med)
            {
                q1.push(q2.top());
                q2.pop();
                q2.push(num);
            }
            else
            {
                q1.push(num);
            }

            med = (q1.top() + q2.top()) / 2.0;
        }

        cout << "Median : " << med << endl;
    }

    return 0;
}