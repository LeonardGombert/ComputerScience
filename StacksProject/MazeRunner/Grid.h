#pragma once
#include "Node.h"

class Grid
{
public:
	Grid();
	~Grid();

	void DisplayGrid();
	Node* RetrieveGrid();

	int gridSize;

private:
	void GenerateGrid();
	Node *grid; // a pointer to a Node
};