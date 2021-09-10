#pragma once

typedef struct Node {
	int value;
	Node* next;
} Node;

class LinkedList
{
private:
	int size = 0;
	Node* head;

	bool headIsNull();

public:
	LinkedList();
	void addNodeToFront(Node* node);
	void removeData(int id);

	bool includes(int value);

	Node* getHead();
};