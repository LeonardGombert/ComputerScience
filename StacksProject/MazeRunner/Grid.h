#pragma once
#include "Node.h"

class Grid
{
public:
	Grid();
	~Grid();

	void DisplayGrid(int mousePosition);
	
	Node* RetrieveGrid();

private:
	Node *grid; // a pointer to a Node
};