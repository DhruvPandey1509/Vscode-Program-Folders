#include<iostream>
#include<limits>
#include<cmath>
using namespace std;

class Heap
{
    public:
    int *harr;
    int capacity; //total available size.
    int heapSize; //total size
    Heap(int size)
    {
        capacity = size;
        heapSize = size;
        harr = new int[capacity];
    }
    void display();              //display values in heap
    int searchNode(int value);   //search a value in heap and return its index
    int extractMin();            //return and remove the smallest value in heap that is the parent node of min heap
    void minHeapify(int i);      //func to restructure the broken heap after extracting the minimum value from the heap;
    void decreaseKey(int i, int value);
    void deletekey(int i);
    void getUnsortedArray();
    void heapSort();
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
void Heap :: getUnsortedArray()
{
    cout<<"Enter "<<capacity<<" number of elements"<<endl;;
    for(int i = 0 ; i < capacity; i++)
    {
        cin>>harr[i];
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
void Heap ::heapSort()
{
    int temp[capacity];
    for(int i = 0 ; i < capacity ; i++)
    {
       temp[i] = extractMin();
       cout<<temp[i]<<" ";
    }
}
int main()
{
    Heap h(6);
    h.getUnsortedArray();
    h.display();

    for(int i = 6/2 - 1 ; i >= 0 ; i--)
    {
        h.minHeapify(i);
    }

    h.display();

    h.heapSort();
    return 0;
}