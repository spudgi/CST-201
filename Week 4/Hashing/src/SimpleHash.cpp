/*
 * SimpleHash.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: Caleb Miller
 */

#include <cstddef>
#include<bits/stdc++.h>
using namespace std;

template<typename K, typename V>

class HashNode
{
    public:
    V value;
    K key;

    HashNode(K key, V value)
    {
        this->value = value;
        this->key = key;
    }
};

template<typename K, typename V>

class HashMap
{
    HashNode<K,V> **arr;
    int capacity;
    int size;
    HashNode<K,V> *dummy;

    public:
    HashMap()
    {
        capacity = 20;
        size=0;
        arr = new HashNode<K,V>*[capacity];

        for(int i=0 ; i < capacity ; i++)
            arr[i] = NULL;

        dummy = new HashNode<K,V>(-1, -1);
    }

    int hashCode(K key)
    {
        return key % capacity;
    }

    //Function to add key value pair
    void insertNode(K key, V value)
    {
        HashNode<K,V> *temp = new HashNode<K,V>(key, value);

        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        //find next free space
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key
               && arr[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= capacity;
        }

        //if new node to be inserted increase the current size
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }

    //Function to delete a key value pair
    V deleteNode(int key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        //finding the node with given key
        while(arr[hashIndex] != NULL)
        {
            //if node found
            if(arr[hashIndex]->key == key)
            {
                HashNode<K,V> *temp = arr[hashIndex];

                //Insert dummy node here for further use
                arr[hashIndex] = dummy;

                // Reduce size
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;

        }

        //If not found return null
        return NULL;
    }

    //Function to search the value for a given key
    V get(int key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        //finding the node with given key
        while(arr[hashIndex] != NULL)
        {
            //if node found return its value
            if(arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }

        //If not found return null
        return NULL;
    }

    int sizeofMap()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void display()
    {
        for(int i=0 ; i<capacity ; i++)
        {
            if(arr[i] != NULL && arr[i]->key != -1)
                cout << "key = " << arr[i]->key
                     <<"  value = "<< arr[i]->value << endl;
        }
    }
};

int main()
{
    HashMap<int, int> *h = new HashMap<int, int>;
    h->insertNode(1234567,1);
    h->insertNode(987122,2);
    h->insertNode(7574532,3);
    h->insertNode(3455352,4);
    h->insertNode(7894563,5);
    h->insertNode(8808383,6);
    h->insertNode(9837373,7);
    h->insertNode(8231573,8);
    h->insertNode(8231573,9);
    h->insertNode(3455352,10);
    h->insertNode(9296632,11);
    h->display();
    cout << h->sizeofMap() <<endl;
    cout << h->deleteNode(2) << endl;
    cout << h->sizeofMap() <<endl;
    cout << h->isEmpty() << endl;
    cout << h->get(2);

    return 0;
}
