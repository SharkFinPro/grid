#include "Grid.h"
#include "LinkedList.h"

#include <iostream>

void printListIncludesId(int id, LinkedList* list)
{
	std::cout << std::boolalpha << "Includes id " << id << "? : " << list->includes(id) << std::endl;
}

int main() {
	Grid grid = Grid(50);
	int keyX, keyY;

	LinkedList* searchList;

	searchList = grid.search(0, 0, 200, 200);
	printListIncludesId(1, searchList);
	
	grid.insertPoint(100, 100, 1, 5, keyX, keyY);
	
	searchList = grid.search(0, 0, 200, 200);
	printListIncludesId(1, searchList);

	grid.removePoint(keyX, keyY, 1);

	searchList = grid.search(0, 0, 200, 200);
	printListIncludesId(1, searchList);

	return 0;
}