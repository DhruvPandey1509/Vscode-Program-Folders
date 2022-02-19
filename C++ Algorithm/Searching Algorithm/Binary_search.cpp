#include<iostream>
using namespace std;

int binary_search(int *arr, int l, int r,int num)
{
    if(l <= r)
    {
        int mid = l + (r - l)/2;
        if(num == arr[mid])
        {
            return mid;
        }
        if(num<arr[mid])
        {
           return binary_search(arr, l, mid-1, num);
        }
        else
        {
            return binary_search(arr, mid+1, r, num);
        }
    }

    return -1;
}

int main()
{
    int arr[] = {4,5,9,10,13,21,25,32,37,45};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num;
    cin>>num;

    int index = binary_search(arr, 0, n-1, num);

    (index == -1) ? cout<<"Number not found"<<endl 
                  : cout<<"Number found at index : "<<index<<endl;
    return 0;
}