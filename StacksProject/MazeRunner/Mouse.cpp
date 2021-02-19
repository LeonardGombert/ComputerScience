#include "Mouse.h"

enum MoveDirection {
	// move the size of the x value
	MoveUp = -6,
	MoveDown = 6,

	// move 1 to the left or right
	MoveLeft = -1,
	MoveRight = 1,

	// the number of elements in the moveDirection enum
	Count = 5
};


Mouse::Mouse(int startingPosition, int sizeX, int sizeY)
{
	gridPosition = startingPosition;
	gridWidth = sizeX;
	gridHeight = sizeY;
	gridSize = sizeX * sizeY;
}

Mouse::~Mouse()
{
}

// check which moves the mouse can legally make based on its position. The Function will return a unique Binary value that represents where the mouse can move
int Mouse::CheckMoves(Node* nodeGrid)
{
	int returnValue = 0;

	if (nodeGrid[gridPosition + MoveUp].bWall == false && nodeGrid[gridPosition + MoveUp].explored == false && nodeGrid[gridPosition + MoveUp].index > nodeGrid[0].index) returnValue += 1;

	if (nodeGrid[gridPosition + MoveDown].bWall == false && nodeGrid[gridPosition + MoveDown].explored == false && nodeGrid[gridPosition + MoveDown].index < nodeGrid[gridSize].index) returnValue += 2;

	if (nodeGrid[gridPosition + MoveLeft].bWall == false && nodeGrid[gridPosition + MoveLeft].explored == false && nodeGrid[gridPosition + MoveLeft].index % gridWidth - 1 != 0) returnValue += 4;

	if (nodeGrid[gridPosition + MoveRight].bWall == false && nodeGrid[gridPosition + MoveRight].explored == false && nodeGrid[gridPosition + MoveRight].index % gridWidth != 0) returnValue += 8;

	else returnValue = 0;

	return returnValue;
}

void Mouse::Step()
{
	// set the current position as explored
	/*nodeGrid[gridPosition].mouse = false;
	nodeGrid[gridPosition].explored = true;

	gridPosition += moveDown;
	nodeGrid[gridPosition].mouse = true;*/
}
