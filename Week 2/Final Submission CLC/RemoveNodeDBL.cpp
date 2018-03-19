/*
 * RemoveNode.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: Caleb Miller
 */

#include <stdio.h>
#include <tchar.h>#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

void deleteNode(struct Node **head_node, struct Node *del_node) {
	if (*head_node == NULL || del_node == NULL)
		return;

	if (*head_node == del_node)
		*head_node = del_node->next;

	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;

	if (del_node->prev != NULL)
		del_node->prev->next = del_node->next;

	free(del_node);
	return;
}

void push(struct Node** head_node, int new_data) {
	//allocating node
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->prev = NULL;

	new_node->next = (*head_node);

	if ((*head_node) != NULL)
		(*head_node)->prev = new_node;

	(*head_node) = new_node;
}

void printList(struct Node *node) {
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

int main() {
	struct Node* head = NULL;

	push(&head, 10);
	push(&head, 20);
	push(&head, 53);
	push(&head, 79);
	push(&head, 32);

	cout << "Original Doubly Linked List Is: " << endl;
	printList(head);

	deleteNode(&head, head);
	deleteNode(&head, head->next);

	cout << "\nLinked List After Deletion at Head and Middle of List: " << endl;
	printList(head);
}
