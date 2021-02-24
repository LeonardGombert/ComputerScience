#pragma once
#include "Grid.h"
#include "Stack.h"

class Mouse
{
public:
	Mouse();
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
};