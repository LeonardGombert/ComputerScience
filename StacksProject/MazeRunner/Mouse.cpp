#include "Mouse.h"

Mouse::Mouse(int startingPosition, int size)
{
	gridPosition = startingPosition;
	gridSize = gridSize;

	// move the size of the x value
	moveUp = -6;
	moveDown = 6;

	// move 1 to the left or right
	moveLeft = -1;
	moveRight = 1;
}

Mouse::~Mouse()
{
}

// reference to the node grid
void Mouse::Step(Node* nodeGrid)
{
	// set the current position as explored
	nodeGrid[gridPosition].mouse = false;
	nodeGrid[gridPosition].explored = true;

	gridPosition += moveDown;
	nodeGrid[gridPosition].mouse = true;
}