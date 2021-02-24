#pragma once
#include "Node.h"

class Grid
{
public:
	Grid(int x, int y, int z);
	~Grid();

	void DisplayGrid(int mousePosition);
	Node* RetrieveGrid();

private:
	void GenerateGrid();
	unsigned int sizeX, sizeY, startingPos;
	Node *grid; // a pointer to a Node
};