#include<iostream>
using namespace std;

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void WaveSort(int *arr, int n)
{
    for(int i = 1 ; i < n-1 ; i += 2)
    {
        if(arr[i] > arr[i-1])
        {
            swap(arr, i, i-1);
        }
        if(arr[i] > arr[i+1])
        {
            swap(arr, i, i+1);
        }
    }

}
void display(int *arr, int n)
{
  for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = {1,3,4,7,5,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    WaveSort(arr, n);
    display(arr, n);
    return 0;
}