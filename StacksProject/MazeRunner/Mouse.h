#pragma once
#include "Grid.h"

class Mouse
{
public:
	Mouse(int startingPosition, int gridSize);
	~Mouse();

	void Step(Node* nodeGrid);

private:
	int CheckMoves(Node* nodeGrid);
	int gridPosition, gridSize;
	signed int moveUp, moveDown, moveLeft, moveRight;
};