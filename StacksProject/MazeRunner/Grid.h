#pragma once
#include "Node.h"

class Grid
{
public:
	Grid();
	~Grid();

private:
	void GenerateGrid();
	Node *grid;
};

