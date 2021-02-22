#include <iostream>
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


Mouse::Mouse(int sizeX, int sizeY, int startingPosition)
{
	gridWidth = sizeX;
	gridHeight = sizeY;
	gridSize = sizeX * sizeY;

	gridPosition = startingPosition;
}

Mouse::~Mouse()
{
}

// check which moves the mouse can legally make based on its position. The Function will return a unique Binary value that represents where the Mouse can move
void Mouse::CheckMoves(Node* nodeGrid)
{
	int moveValue = 0;
	
	if (nodeGrid[gridPosition + MoveUp].bWall == false && nodeGrid[gridPosition + MoveUp].explored == false && gridPosition + MoveUp > 0) moveValue += 1;

	if (nodeGrid[gridPosition + MoveDown].bWall == false && nodeGrid[gridPosition + MoveDown].explored == false && gridPosition + MoveDown < gridSize) moveValue += 2;
	
	if (nodeGrid[gridPosition + MoveLeft].bWall == false && nodeGrid[gridPosition + MoveLeft].explored == false && gridPosition % gridWidth != 0 && gridPosition + MoveLeft > 0) moveValue += 4;

	if (nodeGrid[gridPosition + MoveRight].bWall == false && nodeGrid[gridPosition + MoveRight].explored == false && gridPosition + MoveRight % gridWidth != 0 && gridPosition + MoveRight < gridSize) moveValue += 8;

	Evaluate(moveValue, nodeGrid);
}

void Mouse::Evaluate(int moveValue, Node* nodeGrid)
{
	// set the current position as explored
	nodeGrid[gridPosition].mouse = false;
	nodeGrid[gridPosition].explored = true;

#pragma region One Direction
	switch (moveValue)
	{
	case 0: // can't move anywhere
		break;
	case 1: // move up
		std::cout << "Moving Up" << std::endl;
		gridPosition += MoveUp;
		break;
	case 2: // move down
		std::cout << "Moving Down" << std::endl;
		gridPosition += MoveDown;
		break;
	case 4: // move left
		std::cout << "Moving Left" << std::endl;
		gridPosition += MoveLeft;
		break;
	case 8: // move right
		std::cout << "Moving Right" << std::endl;
		gridPosition += MoveRight;
		break;
	default:
		std::cout << "Mouse can move in more than one direction" << std::endl;
		break;
	}
#pragma endregion

#pragma region Two Directions
	switch (moveValue)
	{
	case 3: // move up and down
		std::cout << "Mouse can Move Up and Down" << std::endl;
		break;
	case 5: // move up and left
		std::cout << "Mouse can Move Up and Left" << std::endl;
		break;
	case 9: // move up and right
		std::cout << "Mouse can Move Up and Right" << std::endl;
		break;

	case 6: // move down and left
		std::cout << "Mouse can Move Down and Left" << std::endl;
		break;
	case 10: // move down and right
		std::cout << "Mouse can Move Down and Right" << std::endl;
		break;

	case 12: // move left and right
		std::cout << "Mouse can Move Left and Right" << std::endl;
		break;

	default:
		std::cout << "Mouse can move in more than two directions" << std::endl;
		break;
	}
#pragma endregion

	nodeGrid[gridPosition].mouse = true;
}
