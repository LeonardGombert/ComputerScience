#pragma once
#include "Grid.h"
#include "Stack.h"

class Mouse
{
public:
	Mouse(int sizeX, int sizeY, int startingPosition);
	~Mouse();

	void CheckMoves(Node* grid);

	Stack movementStack;

private:
	int moveValue;
	Node* nodeGrid;

	void Evaluate();
	
	int gridPosition, gridSize, gridWidth, gridHeight;
};