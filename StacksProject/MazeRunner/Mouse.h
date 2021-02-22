#pragma once
#include "Grid.h"

class Mouse
{
public:
	Mouse(int sizeX, int sizeY, int startingPosition);
	~Mouse();

	void CheckMoves(Node* nodeGrid);

private:
	void Evaluate(int moveValue, Node* nodeGrid);	
	int gridPosition, gridSize, gridWidth, gridHeight;
};