#include <iostream>
#include "Mouse.h"

enum MoveDirection {
	// move the size of the x value
	MoveUp = -6,
	MoveDown = 6,

	// move 1 to the left or right
	MoveLeft = -1,
	MoveRight = 1,
};


Mouse::Mouse(int sizeX, int sizeY, int startingPosition)
{
	gridWidth = sizeX;
	gridHeight = sizeY;
	gridSize = sizeX * sizeY;

	gridPosition = startingPosition;
	movementStack.Push(gridPosition);
}

Mouse::~Mouse()
{
}

// check which moves the mouse can legally make based on its position. The Function will return a unique Binary value that represents where the Mouse can move
void Mouse::CheckMoves(Node* grid)
{
	nodeGrid = grid;
	moveValue = 0;

	if (nodeGrid[gridPosition + MoveUp].bIsWall == false && nodeGrid[gridPosition + MoveUp].bIsExplored == false && nodeGrid[gridPosition + MoveUp].bIsBranching == false && gridPosition + MoveUp > 0) moveValue += 1;

	if (nodeGrid[gridPosition + MoveDown].bIsWall == false && nodeGrid[gridPosition + MoveDown].bIsExplored == false && nodeGrid[gridPosition + MoveDown].bIsBranching == false && gridPosition + MoveDown < gridSize) moveValue += 2;

	if (nodeGrid[gridPosition + MoveLeft].bIsWall == false && nodeGrid[gridPosition + MoveLeft].bIsExplored == false && nodeGrid[gridPosition + MoveLeft].bIsBranching == false && gridPosition % gridWidth != 0 && gridPosition + MoveLeft > 0) moveValue += 4;

	if (nodeGrid[gridPosition + MoveRight].bIsWall == false && nodeGrid[gridPosition + MoveRight].bIsExplored == false && nodeGrid[gridPosition + MoveRight].bIsBranching == false && gridPosition + MoveRight % gridWidth != 0 && gridPosition + MoveRight < gridSize) moveValue += 8;

	Evaluate();
}

void Mouse::Evaluate()
{
	std::cout << "Movement Value is " << moveValue << std::endl;
	// set the current position as explored
	nodeGrid[gridPosition].bIsExplored = true;

#pragma region One Direction
	switch (moveValue)
	{
	case 0: // can't move anywhere
		movementStack.Pop(); // this will continue popping until you reach the original branching node
		gridPosition = movementStack.Peek();
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
		nodeGrid[gridPosition].bIsBranching = true; // set the gridNode as a branching path, so you know where to stop when popping from the stack (?)
		break;
	}
#pragma endregion

#pragma region Two Directions
	switch (moveValue)
	{
	case 3: // move up and down
		std::cout << "Mouse can Move Up and Down" << std::endl;
		gridPosition += MoveUp;
		break;
	case 5: // move up and left
		std::cout << "Mouse can Move Up and Left" << std::endl;
		gridPosition += MoveUp;
		break;
	case 9: // move up and right
		std::cout << "Mouse can Move Up and Right" << std::endl;
		gridPosition += MoveUp;
		break;

	case 6: // move down and left
		std::cout << "Mouse can Move Down and Left" << std::endl;
		gridPosition += MoveDown;
		break;
	case 10: // move down and right
		std::cout << "Mouse can Move Down and Right" << std::endl;
		gridPosition += MoveDown;
		break;

	case 12: // move left and right
		std::cout << "Mouse can Move Left and Right" << std::endl;
		gridPosition += MoveLeft;
		break;

	default:
		std::cout << "Mouse can move in more than two directions" << std::endl;
		break;
	}
#pragma endregion

	movementStack.Push(gridPosition);
}