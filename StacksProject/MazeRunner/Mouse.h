#pragma once
#include "Grid.h"
#include "Stack.h"

class Mouse
{
public:
	Mouse(const int sizeX, const int sizeY, const int startPosition);
	~Mouse();

	void CheckMoves(Node* grid);
	int RetrievePosition();

private:
	void Evaluate();
	int PickRandomDirection(int const a, int const b, int const c);

	Node* nodeGrid;	

	Stack movementStack;

	int gridPosition, gridSize;
	int moveValue;

	int mazeSizeX, mazeSizeY;
	int moveUp = -mazeSizeX, moveDown = mazeSizeX, moveLeft = -1, moveRight = 1;
};