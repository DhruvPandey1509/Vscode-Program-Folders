#include <iostream>
#include "hashtable.h"
using namespace std;

int main()
{
    Hashtable<int> h;
    h.insert("Mango", 100);
    h.insert("Apple", 120);
    h.insert("Banana", 140);
    h.insert("Orange", 200);
    h.insert("Litchi", 210);
    h.insert("Pineapple", 220);
    h.insert("Guawa", 230);
    h.insert("DragonFruit", 250);
    h.insert("Strawberry", 310);
    h.insert("Razzberry", 330);
    h.insert("Blueberry", 320);
    h.insert("Grape", 30);
    h.insert("Melon", 350);

    string fruit;
    cout << "Enter fruit to search" << endl;
    cin >> fruit;

    h.search(fruit) != NULL ? cout << "Price of " << fruit << " : " << *(h.search(fruit)) << endl : cout << fruit << " not present" << endl;
    h.print();

    h.erase("M");
    h.print();

    // h["newFruit"] = 200;
    // cout << "New Fruit Cost : " << h["newFruit"] << endl;
    // h["newFruit"] += 20;
    // cout << "New Fruit Cost : " << h["newFruit"] << endl;

    return 0;
}