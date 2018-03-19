/* J. Ricardo Lopez, C++, March 18 2018 */
#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

/* A function to insert at the end*/
void insertEnd(struct Node** start, int value)
{
    // When the list is empty then a single node
    // will be created
    if (*start == NULL)
    {
        struct Node* new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }

    //When the list is not empty

  /*finding the node*/
    Node *last = (*start)->prev;

  /* Dinamically creating a Node*/

    struct Node* new_node = new Node;

    new_node->data = value;

    /* Start is the next new code*/
    new_node->next = *start;

    /* Make a new node befor start*/
    (*start)->prev = new_node;


    new_node->prev = last;

    /* Make new node next from the old last */
    last->next = new_node;
}


void insertBegin(struct Node** start, int value)
{

    struct Node *last = (*start)->prev;

    struct Node* new_node = new Node;
    new_node->data = value;   // Inserting the data

    /* Settomg up previous, next of the new node*/

    new_node->next = *start;

    new_node->prev = last;
     // Update next and previous

    last->next = (*start)->prev = new_node;

    // Update start pointer
    *start = new_node;
}


void insertAfter(struct Node** start, int value1,
                                      int value2)
{
    struct Node* new_node = new Node;
    new_node->data = value1; // Inserting the data

    // Having value 2 and next node for it
    struct Node *temp = *start;
    while (temp->data != value2)
        temp = temp->next;
    struct Node *next = temp->next;

    // Putting a new node
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}


void display(struct Node* start)
{
    struct Node *temp = start;

    printf("\nTraversal in forward direction \n");
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);

    printf("\nTraversal in reverse direction \n");
    Node *last = start->prev;
    temp = last;
    while (temp->prev != last)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

/* To test the above funcions */
int main()
{
    /* A empty list to start Start  */

    struct Node* start = NULL;

    // Linked List becomes null

    insertEnd(&start, 5);

    // Insert 4 in the beginning

    insertBegin(&start, 4);

    // Putting 7 in the end
    // it result like this  4->5->7
    insertEnd(&start, 7);

    //Putting 8 in the end. so it become 4->5->7->8

    insertEnd(&start, 8);

    //Putting 6, after 5. Then linked list will change I
    insertAfter(&start, 6, 5);

    printf("Created circular doubly linked list is: ");
    display(start);

    return 0;
}




