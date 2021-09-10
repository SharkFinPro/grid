#pragma once
#include <unordered_map>
#include "LinkedList.h"

class Grid
{
private:
	int binSize;
	std::unordered_map<int, std::unordered_map<int, LinkedList*>> data;

	void findBinKey(int x, int y, int* keyX, int* keyY);
	LinkedList* findBin(int keyX, int keyY);

public:
	Grid(int binSize);
	void printGridSize();
	
	void addData(int x, int y, int data, int* keyX, int* keyY);
	void removeData(int keyX, int keyY, int id);

	LinkedList* search(int x, int y, int width, int height);
};