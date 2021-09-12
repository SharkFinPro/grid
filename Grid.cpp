#include "Grid.h"
#include <iostream>

/* Public Methods */

Grid::Grid(int binSize)
{
	this->binSize = binSize;
}

void Grid::insertPoint(int x, int y, int id, int data, int* keyX, int* keyY)
{
	findBinKey(x, y, keyX, keyY);
	LinkedList* bin = findBin(*keyX, *keyY);
	Node* node = new Node({ id, data, nullptr});
	
	bin->addNodeToFront(node);
}

void Grid::removePoint(int keyX, int keyY, int id)
{
	LinkedList* bin = findBin(keyX, keyY);
	bin->removeNode(id);
}

LinkedList* Grid::search(int x, int y, int width, int height)
{
	LinkedList* list = new LinkedList();
	
	for (int i = x; i < x + width; i += binSize)
	{
		for (int j = y; j < y + height; j += binSize)
		{
			int keyX = 0;
			int keyY = 0;
			findBinKey(i, j, &keyX, &keyY);
			LinkedList* bin = findBin(keyX, keyY);
			Node* currentNode = bin->getHead();

			for (int i = 0; i < bin->getSize(); i++)
			{
				if (!list->includes(currentNode->id))
				{
					Node* node = new Node({ currentNode->id, currentNode->data, nullptr });
					list->addNodeToFront(node);
				}

				if (currentNode->next != nullptr)
				{
					currentNode = currentNode->next;
				}
			}
		}
	}

	return list;
}

int Grid::getBinSize()
{
	return binSize;
}

/* Private Methods */

void Grid::findBinKey(int x, int y, int* keyX, int* keyY)
{
	*keyX = x / binSize;
	*keyY = y / binSize;
}

LinkedList* Grid::findBin(int keyX, int keyY)
{
	auto xSearch = bins.find(keyX);
	if (xSearch == bins.end()) {
		std::unordered_map<int, LinkedList*>* newMap = new std::unordered_map<int, LinkedList*>;
		bins.insert({ keyX, newMap });
	}
	
	std::unordered_map<int, LinkedList*>* xVal = bins.at(keyX);

	auto ySearch = bins.at(keyX)->find(keyY);
	if (ySearch == xVal->end()) {
		LinkedList* newList = new LinkedList();
		xVal->insert({ keyY, newList });
	}

	LinkedList* list = xVal->at(keyY);

	return list;
}