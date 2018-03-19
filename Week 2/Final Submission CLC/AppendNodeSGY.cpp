/*
 * singlyLinked.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: Caleb Miller
 */

#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;

  public:
    Node() {}; // @suppress("Class members should be properly initialized")
    void SetData(int aData) { data = aData; };
    void SetNext(Node* aNext) { next = aNext; };
    int Data() { return data; };
    Node* Next() { return next; };
};

class List {
    Node *head;
  public:
    List() { head = NULL; };
    void Print();
    void Append(int data);
    void Delete(int data);
};

/**
 * Print the contents of the list
 */
void List::Print() {

    Node *tmp = head;

    if ( tmp == NULL ) {
    cout << "EMPTY" << endl;
    return;
    }

    if ( tmp->Next() == NULL ) {
    cout << tmp->Data();
    cout << " --> ";
    cout << "NULL" << endl;
    }
    else {
    do {
        cout << tmp->Data();
        cout << " --> ";
        tmp = tmp->Next();
    }
    while ( tmp != NULL );

    cout << "NULL" << endl;
    }
}

/**
 * Append a node to the linked list
 */
void List::Append(int data) {

    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);

    Node *tmp = head;

    if ( tmp != NULL ) {

    while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
    }

    tmp->SetNext(newNode);
    }
    else {
    head = newNode;
    }
}

/**
 * Delete a node from the list
 */
void List::Delete(int data) {

    Node *tmp = head;

    if ( tmp == NULL )
    return;

    if ( tmp->Next() == NULL ) {
    delete tmp;
    head = NULL;
    }
    else {
    Node *prev;
    do {
        if ( tmp->Data() == data ) break;
        prev = tmp;
        tmp = tmp->Next();
    } while ( tmp != NULL );

    prev->SetNext(tmp->Next());

    delete tmp;
    }
}

int main() {
    // New list
    List list;

    // Append nodes to the list
    list.Append(100);
    list.Print();
    list.Append(200);
    list.Print();
    list.Append(300);
    list.Print();
    list.Append(400);
    list.Print();
    list.Append(500);
    list.Print();

    // Delete nodes from the list
    list.Delete(400);
    list.Print();
    list.Delete(300);
    list.Print();
    list.Delete(200);
    list.Print();
    list.Delete(500);
    list.Print();
    list.Delete(100);
    list.Print();
}


