/*
 * SinglyPalindrome.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: gage_
 */


#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* next;
};

bool isPalindromeUtil(string str) {
    int length = str.length();

    for (int i=0; i<length/2; i++)
        if (str[i] != str[length-i-1])
            return false;

    return true;
}

bool isPalindrome(Node *node) {
    string str = "";
    while (node != NULL) {
        str.append(node->data);
        node = node->next;
    }

    return isPalindromeUtil(str);
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    printf("NULL\n");
}

Node *newNode(const char *str) {
    Node *new_node = new Node;
    new_node->data = str;
    new_node->next = NULL;
    return new_node;
}

int main() {
    Node *head = newNode("a");
    head->next = newNode("bc");
    head->next->next = newNode("d");
    head->next->next->next = newNode("dcb");
    head->next->next->next->next = newNode("a");

    isPalindrome(head)? printf("true\n"):
                        printf("false\n");

    return 0;
}


