#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <typename T>
class Node
{
public:
    string key;
    T value;
    Node *next;

    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
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
        // Save the ptr to the oldTable and we will do insertion in the new table
        Node<T> **oldTable = table;

        table = new Node<T> *[2 * ts + 1]; // ideally you show make it prime
        int oldTs = ts;
        cs = 0;
        ts = 2 * ts + 1;

        // here we are resizing our table and not naming it newtable so that we can use the previously defined table as new table
        // and making a new datatype for old table above
        table = new Node<T> *[ts];

        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }

        // Copy elements from old table to new table
        for (int i = 0; i < oldTs; i++)
        {
            Node<T> *temp = oldTable[i];

            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;

                // append in the new table
                insert(key, value);
                temp = temp->next;
            }

            // destroy the ith  linked list
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    } 

public:
    Hashtable(int default_size = 7)
    {
        cs = 0;
        ts = default_size;

        table = new Node<T> *[ts];
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T val)
    {
        // Next
        int idx = hashFn(key);

        Node<T> *n = new Node<T>(key, val);

        // Insertion at the head of the Linked list
        n->next = table[idx];
        table[idx] = n;

        cs++;

        float load_factor = cs / float(ts);
        if (load_factor > 0.7)
        {
            rehash();
        }
    }
    T *search(string key)
    {
        int idx = hashFn(key);

        Node<T> *temp = table[idx];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &(temp->value);
            }
            temp = temp->next;
        }
        return NULL;
    }
    bool isPresent(string key)
    {
        int *iP = search(key);
        if(iP == NULL)
        {
            return false;
        }
        return true;
    }
    T &operator[](string key)
    {
        // return the value
        // if key is not found then create a new node and return
        //  return the existing node
        T *valueFound = search(key);
        if (valueFound == NULL)
        {
            T object;
            insert(key, object);
            valueFound = search(key);
        }
        return *valueFound;
    }
    void erase(string key)
    {
        if(!isPresent(key))
        {
            cout<<key<<" not present"<<endl;
            return;
        }
        int idx = hashFn(key);
        Node<T> *todelete = table[idx];
        if (todelete->key == key)
        {
            Node<T> *temp = todelete;
            table[idx] = todelete->next;
            delete temp;
            return;
        }
        Node<T> *temp = todelete->next;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                todelete->next = temp->next;
                delete temp;
                return;
            }  
            todelete = todelete->next;
            temp = temp->next;
        }
    }
    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            cout << "Bucket" << i << "->";

            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};