#ifndef A_H
#define A_H
#include "stdafx.h"
#include <stdlib.h>

class DoublyLinkedList{

	struct Node{
		Node* next;
		Node* prev;
		int data;
	};

	DoublyLinkedList();
	~DoublyLinkedList();

	Node* AddNode(int data, Node* head);
	Node* RemoveNode(Node* nodeToDelete);

};
#endif