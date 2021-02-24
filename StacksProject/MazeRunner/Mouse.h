#pragma once
#include "Grid.h"
#include "Stack.h"

class Mouse
{
public:
	Mouse();
	~Mouse();

	Stack movementStack;

	void CheckMoves(Node* grid);

private:
	void Evaluate();
	int PickRandomDirection(int const a, int const b, int const c);

	Node* nodeGrid;	

	int gridPosition, gridSize;
	int moveValue;
};