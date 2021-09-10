#include "Grid.h"
#include "LinkedList.h"

#include <iostream>

int main() {
	Grid grid = Grid(250);
	int* keyX = 0;
	int* keyY = 0;

	LinkedList* list;

	list = grid.search(0, 0, 200, 200);
	std::cout << "Includes id 1? : " << list->includes(1) << std::endl;

	grid.addData(100, 100, 1, keyX, keyY);


	list = grid.search(0, 0, 200, 200);
	std::cout << "Includes id 1? : " << list->includes(1) << std::endl;

	return 0;
}