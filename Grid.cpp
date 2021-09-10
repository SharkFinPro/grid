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
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = data;

	bin->addNodeToFront(node);
}

void Grid::removeData(int keyX, int keyY, int id)
{
	LinkedList* bin = findBin(keyX, keyY);
	bin->removeData(id);
}


LinkedList* Grid::search(int x, int y, int width, int height) // x, y = top left of search box
{
	// Nested For loop, find bins in all x & y values, for loop increases by binsize.
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

	for (int i = x; i < x + width; i += binSize)
	{
		for (int j = y; j < j + height; j += binSize)
		{
			// loop through every value in bin
			// -> while looping, check to see if list includes each value from the bin
			//    -> if list already includes the value, return. otherwise, add to list.
			Node* currentNode = findBin(i, j)->getHead();

			while (currentNode != nullptr)
			{
				if (!list->includes(currentNode->value))
				{
					Node* node = (Node*)malloc(sizeof(Node));
					node->value = currentNode->value;
					list->addNodeToFront(node);
				}
				currentNode = currentNode->next;
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
	/*LinkedList* bin = data.at(keyX).at(keyY);
	if (bin == NULL) {
		bin = (LinkedList*)malloc(sizeof(LinkedList));
	}

	return bin;*/

	auto search = data.find(keyX);
	if (keyX == data.end()) {
		//insert new data
	}
}