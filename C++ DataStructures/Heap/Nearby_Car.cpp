#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Car
{
public:
    string id;
    int x, y;
    Car(string id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dis() const // returning square of the distance
    {
        return x * x + y * y;
    }
};

class CarCompare
{
public:
    // Max Heap
    bool operator()(Car A, Car B)
    {
        return A.dis() < B.dis();
    }
};

void printNearestCar(vector<Car> cars, int k)
{
    // Create a max heap of size k
    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);

    for (int i = k; i < cars.size(); i++)
    {
        auto car = cars[i];
        if (car.dis() < max_heap.top().dis())
        {
            max_heap.pop();
            max_heap.push(car);
        }

        // Print all the cars inside the heap they will be smallest
        vector<Car> output;
        while (!max_heap.empty())
        {
            // cout << max_heap.top().id << endl;
            output.push_back(max_heap.top());
            max_heap.pop();
        }
        // output contains min distance but in descending order so reverse to get in ascending order as per the requirement of the question
        //  vector of k nearest cars
        reverse(output.begin(), output.end());
        for (auto car : output)
        {
            cout << car.id << endl;
        }

        return;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    string id;
    int x, y;

    vector<Car> cars;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> x >> y;
        Car car(id, x, y);
        cars.push_back(car);
    }

    printNearestCar(cars, k);

    return 0;
}