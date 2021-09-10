#include "LinkedList.h"
#include <iostream>

/* Public Methods */

LinkedList::LinkedList()
{
	head = nullptr;
}

void LinkedList::addNodeToFront(Node* node)
{
	if (headIsNull())
	{
		head = node;
		return;
	}

	node->next = head;
	head = node;
};

void LinkedList::removeData(int id)
{
	if (headIsNull())
	{
		return;
	}

	Node* lastNode = nullptr;
	Node* currentNode = head;
	while (currentNode->next != nullptr)
	{
		if (currentNode->value == id) {
			lastNode->next = currentNode->next;
			return;
		}

		lastNode = currentNode;
		currentNode = currentNode->next;
	}
};

Node* LinkedList::getHead()
{
	return head;
}

bool LinkedList::includes(int value)
{
	if (headIsNull())
	{
		return false;
	}
	
	Node* lastNode = nullptr;
	Node* currentNode = head;

	while (currentNode != nullptr)
	{
		if (currentNode->value == value)
		{
			return true;
		}
		lastNode = currentNode;
		currentNode = currentNode->next;
	}

	return false;
}

/* Private Methods */
bool LinkedList::headIsNull()
{
	return head == nullptr;
}