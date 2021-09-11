#include "Grid.h"
#include <iostream>

/* Public Methods */

Grid::Grid(int binSize)
{
	this->binSize = binSize;
}

void Grid::printGridSize()
{
	std::cout << "Bin Size: " << this->binSize << std::endl;
}

void Grid::addData(int x, int y, int data, int* keyX, int* keyY)
{
	findBinKey(x, y, keyX, keyY);
	LinkedList* bin = findBin(*keyX, *keyY);
	Node* node = new Node;
	node->value = data;
	
	bin->addNodeToFront(node);
}

void Grid::removeData(int keyX, int keyY, int id)
{
	LinkedList* bin = findBin(keyX, keyY);
	bin->removeData(id);
}


LinkedList* Grid::search(int x, int y, int width, int height)
{
	LinkedList* list = new LinkedList;
	
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
				if (!list->includes(currentNode->value))
				{
					Node* node = new Node;
					node->value = currentNode->value;
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

/* Private Methods */

void Grid::findBinKey(int x, int y, int* keyX, int* keyY)
{
	*keyX = x / binSize;
	*keyY = y / binSize;
}

LinkedList* Grid::findBin(int keyX, int keyY)
{
	auto xSearch = data.find(keyX);
	if (xSearch == data.end()) {
		std::unordered_map<int, LinkedList*>* newMap = new std::unordered_map<int, LinkedList*>;
		data.insert({ keyX, newMap });
	}
	
	std::unordered_map<int, LinkedList*>* xVal = data.at(keyX);

	auto ySearch = data.at(keyX)->find(keyY);
	if (ySearch == xVal->end()) {
		LinkedList* newList = new LinkedList();
		xVal->insert({ keyY, newList });
	}

	LinkedList* list = xVal->at(keyY);

	return list;
}