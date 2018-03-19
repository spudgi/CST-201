/*
 * CopyListCRC.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: Caleb Miller
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

struct item {
	int data;
	struct item *next;
};

class CLList {
private:
	item * head;
	item * tail;
public:
	CLList() {
		head = NULL;
		tail = NULL;
	}
	void createNode(int value) {
		item *n = new item;
		n->data = value;
		n->next = NULL;

		if (head == NULL) {
			head = n;
			tail = n;
			n = NULL;
		}

		else {
			n->next = head;
			tail->next = n;
			tail = n;

		}
	}

	void display() {
		item *pos = new item;
		pos = head;

		do {
			cout << pos->data << "\t" << endl;
			pos = pos->next;
		} while (pos != head);
	}

	void copyList(CLList list) {
		CLList *listP = new CLList;
		*listP = list;

		item *pos = new item;
		pos = listP->head;

		do {
			this->createNode(pos->data);
			pos = pos->next;
		} while (pos != listP->head);
	}
};



int main() {
	CLList A, B;
	A.createNode(1);
	A.createNode(2);
	A.createNode(3);
	A.createNode(4);
	A.createNode(50);
	cout << "display A" << endl;
	A.display();
	cout << "copying A to B" << endl;
	B.copyList(A);
	cout << "display B" << endl;
	B.display();
	cout << "added node to B" << endl;
	B.createNode(60);
	cout << "display B" << endl;
	B.display();
	cout << "display A" << endl;
	A.display();
    return 0;
}
