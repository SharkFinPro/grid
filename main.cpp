#include "Grid.h"
#include "LinkedList.h"

#include <iostream>

void printListIncludesId(int id, LinkedList* list)
{
	std::cout << "Includes id " << id << "? : " << list->includes(id) << std::endl;
}

int main() {
	Grid grid = Grid(50);
	int keyX = 0;
	int keyY = 0;

	LinkedList* list;

	list = grid.search(0, 0, 200, 200);
	printListIncludesId(1, list);
	
	grid.insertPoint(100, 100, 1, 5, keyX, keyY);
	
	list = grid.search(0, 0, 200, 200);
	printListIncludesId(1, list);

	grid.removePoint(keyX, keyY, 1);

	list = grid.search(0, 0, 200, 200);
	printListIncludesId(1, list);

	return 0;
}