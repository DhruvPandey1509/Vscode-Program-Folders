#include<iostream>
#include<cmath>
#include<limits>
using namespace std;

class Heap
{
    public:
    int *harr;
    int capacity; //total available size.
    int heapSize; //current size i.e number of elements present.
    Heap(int size)
    {
        capacity = size;
        heapSize = 0;
        harr = new int[capacity];
    }
    void insert(int k);          //insert value in heap
    void display();              //display values in heap
    int searchNode(int value);   //search a value in heap and return its index
    int extractMin();            //return and remove the smallest value in heap that is the parent node of min heap
    void minHeapify(int i);      //func to restructure the broken heap after extracting the minimum value from the heap;
    void decreaseKey(int i, int value);
    void deletekey(int i);
    int parent(int i)            //returns index of parent node
    {
        return (i-1)/2;
    } 
    int leftNode(int i)          //returns index of left node
    {
        return (2*i + 1);
    }
    int rightNode(int i)         //returns index of left node
    {
        return (2*i + 2);
    }
};
void swap(int &x, int &y)        //swap the values
{
    int temp = x;
    x = y;
    y = temp;
}
// void Heap ::searchNode(int value)
// {
    
// }
void Heap ::decreaseKey(int i, int value)
{
    harr[i] = value;
    while(i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i],harr[parent(i)]);
        i = parent(i);
    }
}
void Heap::deletekey(int i)
{
    decreaseKey(i,INT32_MIN);
    extractMin();
}
void Heap ::insert(int k)
{
    if(heapSize == capacity)
    {
        cout<<"Overflow : Heap Full";
        return;
    }
    heapSize++;
    int i = heapSize-1;
    harr[i] = k;
    while(i != 0 && harr[parent(i)] > harr[i])
    {
       swap(harr[i],harr[parent(i)]);
       i = parent(i);
    }
}
void Heap ::minHeapify(int i)
{
   int l = leftNode(i);
   int r = rightNode(i);
   int smallest = i;
   if(l < heapSize && harr[l] < harr[i])
   {
       smallest = l;
   }
   if(r < heapSize && harr[r] < harr[smallest])
   {
       smallest = r; 
   }
   if(smallest != i)
   {
       swap(harr[i],harr[smallest]);
       minHeapify(smallest);
   }
}
int Heap ::extractMin()
{
    if(heapSize <= 0)
    {
        return -1;
    }
    if(heapSize == 1)
    {
        heapSize--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heapSize-1];
    heapSize--;
    minHeapify(0);
    return root;
}
void Heap ::display()
{
    for(int i = 0 ; i < heapSize; i++)
    {
        cout<<harr[i]<<" ";
    }
    cout<<endl;
}
 

int main()
{
    Heap h(10);
    h.insert(1);
    h.insert(2);
    h.insert(7);
    h.insert(5);
    h.insert(8);
    h.insert(0);
    h.insert(6);
    h.display();

    h.extractMin();
    h.display();

    h.deletekey(4);
    h.display();
    
    int size;
    cout<<"Enter Size"<<endl;
    cin>>size;
    int arr[size];
    for(auto &i : arr)
    {
       cin>>i;
    }
    return 0;
}