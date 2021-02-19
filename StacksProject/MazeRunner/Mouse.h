#pragma once
#include "Grid.h"

class Mouse
{
public:
	Mouse(int startingPosition, int sizeX, int sizeY);
	~Mouse();

	int CheckMoves(Node* nodeGrid);

private:
	void Step();
	int gridPosition, gridSize, gridWidth, gridHeight;
};