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
	
	Node* nodeGrid;	

	int gridPosition, gridSize;
	int moveValue;
};