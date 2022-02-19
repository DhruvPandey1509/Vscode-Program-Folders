#include<iostream>
#include<algorithm>
using namespace std;

int feasibility(int *boards, int n, int limit)
{
    int sum = 0 , painters = 1;

    for(int i = 0 ; i < n ; i++)
    {
        sum += boards[i];
        if(sum > limit) //is sum becomes greater than limit
        {
            sum = boards[i];
            painters++; //increasing the number of painters
        }
    }

    return painters;
}

int findPartition(int *boards, int n, int m)// n = number of painting boards, m = number of painters, boards array stores size of painting boards
{
    int totalLength = 0, k = 0;
    for(int i = 0 ; i < n ; i++)
    {
        k = max(k, boards[i]);
        totalLength += boards[i];
    }

    int low = k, high = totalLength;
    int mid;
    while(low < high)
    {
        mid = low + (high - low)/2;
        int painters = feasibility(boards, n, mid);

        if(painters <= m)// if true we will srch in left half
        {
            high = mid;
        }
        else
        {
            low = mid+1; //searching in right half
        }
    }

    return low;
}
int main()
{
    int boards[] = {10,20,30,40};
    int n = 4, m = 2;

    cout<<"Minimum unit of time to paint : "<<findPartition(boards, n, m)<<endl;

    return 0;
}