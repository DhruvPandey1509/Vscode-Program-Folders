#include <iostream>
using namespace std;

class Heap
{
    int heapSize;
    int capacity;
    int *harr;

public:
    Heap(int size)
    {
        heapSize = 0;
        capacity = size;
        harr = new int[capacity];
    }

    int parent(int i) //returns index of parent node
    {
        return (i - 1) / 2;
    }
    int leftNode(int i) //returns index of left node
    {
        return (2 * i + 1);
    }
    int rightNode(int i) //returns index of left node
    {
        return (2 * i + 2);
    }
    void insert(int k);
    void minHeapify(int i);
    int extractMin();
    void deleteHeap();

};
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void Heap ::minHeapify(int i)
{
    int l = leftNode(i);
    int r = rightNode(i);
    int smallest = i;

    if (l < heapSize && harr[l] < harr[smallest])
    {
        smallest = l;
    }
    if (r < heapSize && harr[r] < harr[smallest])
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        minHeapify(smallest);
    }
}
int Heap ::extractMin()
{
    if(heapSize == 0)
    {
        cout<<"Empty"<<endl;
        return INT32_MAX;
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
    return 0;
}
void Heap ::insert(int k)
{
    while (heapSize == capacity)
    {
        cout << "Empty" << endl;
        return;
    }
    heapSize++;
    int i = heapSize - 1;
    harr[i] = k;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[parent(i)], harr[i]);
        i = parent(i);
    }
}
void Heap :: deleteHeap()
{
    
}


int main()
{
    
    return 0;
}