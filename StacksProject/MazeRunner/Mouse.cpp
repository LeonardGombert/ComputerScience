#include <iostream>
#include "Definitions.h"
#include "Mouse.h"

enum MoveDirection {
	// move the size of the x value
	MoveUp = -mazeSizeX,
	MoveDown = mazeSizeX,

	// move 1 to the left or right
	MoveLeft = -1,
	MoveRight = 1,
};


Mouse::Mouse()
{
	movementStack;
	gridSize = mazeSizeX * mazeSizeY;
	gridPosition = mazeStart;
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

	if (nodeGrid[gridPosition + MoveUp].bIsWall == false && nodeGrid[gridPosition + MoveUp].bIsExplored == false && gridPosition + MoveUp > 0) moveValue += 1;

	if (nodeGrid[gridPosition + MoveDown].bIsWall == false && nodeGrid[gridPosition + MoveDown].bIsExplored == false && gridPosition + MoveDown < gridSize) moveValue += 2;

	if (nodeGrid[gridPosition + MoveLeft].bIsWall == false && nodeGrid[gridPosition + MoveLeft].bIsExplored == false && gridPosition % mazeSizeX != 0 && gridPosition + MoveLeft > 0) moveValue += 4;

	if (nodeGrid[gridPosition + MoveRight].bIsWall == false && nodeGrid[gridPosition + MoveRight].bIsExplored == false && (gridPosition +1) % mazeSizeX != 0 && gridPosition + MoveRight < gridSize) moveValue += 8;

	Evaluate();
}

void Mouse::Evaluate()
{
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
		gridPosition += MoveUp;
		break;
	case 2: // move down
		gridPosition += MoveDown;
		break;
	case 4: // move left
		gridPosition += MoveLeft;
		break;
	case 8: // move right
		gridPosition += MoveRight;
		break;
	default: // mouse can move in more than one direction
		break;
	}
#pragma endregion

#pragma region Two Directions
	switch (moveValue)
	{
	case 3: // move up and down
		gridPosition += MoveUp;
		break;
	case 5: // move up and left
		gridPosition += MoveUp;
		break;
	case 9: // move up and right
		gridPosition += MoveUp;
		break;

	case 6: // move down and left
		gridPosition += MoveDown;
		break;
	case 10: // move down and right
		gridPosition += MoveDown;
		break;

	case 12: // move left and right
		gridPosition += MoveLeft;
		break;

	default: // mouse can move in more than two directions
		break;
	}
#pragma endregion

#pragma region Three Directions
	switch (moveValue)
	{
	case 7 : // move up, down and left
		gridPosition += MoveUp;
		break;

	case 11: // move up, down and right
		gridPosition += MoveUp;
		break;

	case 13 : // move up, left and right
		gridPosition += MoveUp;
		break;

	case 14 : // move down, left and right
		gridPosition += MoveDown;
		break;

	default:
		break;
	}
#pragma endregion

	movementStack.Push(gridPosition);
}