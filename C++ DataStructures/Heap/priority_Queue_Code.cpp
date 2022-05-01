#include <iostream>
#include <queue>
using namespace std;

class Compare
{
public:
    // minHeap
    // bool operator()(int a, int b)
    // {
    //     return a > b;
    // }

    // maxHeap
    // bool operator()(int a, int b)
    // {
    //     return a < b;
    // }
};

int main()
{
    int a[] = {10, 4, 21, 16, 13, 43};
    int n = sizeof(a) / sizeof(a[0]);
    priority_queue<int> heap;

    for (auto x : a)
    {
        heap.push(x);
    }
    cout << "Max Heap" << endl;
    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;
    priority_queue<int, vector<int>, greater<int>> heap1; // greater<int> is an inbuilt comparator
    for (auto x : a)
    {
        heap1.push(x);
    }
    cout << "Min  Heap" << endl;
    while (!heap1.empty())
    {
        cout << heap1.top() << " ";
        heap1.pop();
    }
    return 0;
}