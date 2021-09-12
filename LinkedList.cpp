#include "LinkedList.h"
#include <iostream>

/* Public Methods */

void LinkedList::addNodeToFront(Node* node)
{
	size++;
	if (headIsNull())
	{
		head = node;
		return;
	}

	node->next = head;
	head = node;
};

void LinkedList::removeNode(int id)
{
	if (headIsNull())
	{
		return;
	}

	Node* lastNode = nullptr;
	Node* currentNode = head;
	while (currentNode != nullptr)
	{
		if (currentNode->id == id) {
			size--;
			if (lastNode == nullptr)
			{
				head = nullptr;
				return;
			}
			lastNode->next = currentNode->next;
			return;
		}

		lastNode = currentNode;
		currentNode = currentNode->next;
	}
};

bool LinkedList::includes(int id)
{
	if (headIsNull())
	{
		return false;
	}
	
	Node* lastNode = nullptr;
	Node* currentNode = head;

	while (currentNode != nullptr)
	{
		if (currentNode->id == id)
		{
			return true;
		}

		lastNode = currentNode;
		currentNode = currentNode->next;
	}

	return false;
}

Node* LinkedList::getHead()
{
	return head;
}

int LinkedList::getSize()
{
	return size;
}

/* Private Methods */
bool LinkedList::headIsNull()
{
	return head == nullptr;
}