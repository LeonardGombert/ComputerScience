#pragma once
#include "Node.h"

class Grid
{
public:
	Grid(int x, int y, int z, int w);
	~Grid();

	void DisplayGrid(int mousePosition);
	
	Node* RetrieveGrid();

	int exitNode, startNode;

private:
	void GenerateGrid();
	unsigned int sizeX, sizeY;
	Node *grid; // a pointer to a Node
};