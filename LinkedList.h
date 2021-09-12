#pragma once

typedef struct Node {
	int id;
	int data;
	Node* next;
} Node;

class LinkedList
{
private:
	int size = 0;
	Node* head = nullptr;

	bool headIsNull();

public:
	void addNodeToFront(Node* node);
	void removeNode(int id);

	bool includes(int id);

	Node* getHead();
	int getSize();
};