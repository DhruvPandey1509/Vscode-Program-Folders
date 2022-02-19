#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Node
{
    string key;
    T value;
    Node *next;

public:
    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

template <typename T>
class Hashtable
{
    Node<T> **table;
    int cs; // total entries that have been inserted
    int ts; // size of table
    int hashFn(string key)
    {
        int idx = 0;
        int power = 1;

        for (auto ch : key)
        {
            idx = (idx + ch * power) % ts;
            power = (power * 29) % ts;
        }

        return idx;
    }
    void rehash()
    {
        Node<T> **oldTable = table;

        table = new Node<T> *[2 * ts + 1];
        int oldTs = ts;
        ts = 2 * ts + 1;

        for(int i = 0 ; i < ts; i++)
        {
            table[i] = NULL;
        }

        for(int i = 0 ; i < oldTs; i++)
        {
            Node<T>
        }
    }

public:
    Hashtable(int default_size = 10)
    {
        cs = 0;
        ts = default_size;
        table = new Node<T> *[ts];
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T value)
    {
        int idx = hashFn(key);

        Node<T> *n = new Node<T> *(key, value);

        n->next = table[idx];
        table[idx] = n;

        cs++;
    }
}

int
main()
{

    return 0;
}