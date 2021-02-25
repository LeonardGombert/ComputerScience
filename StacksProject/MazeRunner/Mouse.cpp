#include <iostream>
#include <random>
#include "Mouse.h"

Mouse::Mouse(const int sizeX, const int sizeY, const int startPosition)
{
	mazeSizeX = sizeX;
	mazeSizeY = sizeY;

	// set the movement values
	moveUp = -mazeSizeX;
	moveDown = mazeSizeX;
	moveLeft = -1;
	moveRight = 1;

	// set the grid values
	gridSize = mazeSizeX * mazeSizeY;
	gridPosition = startPosition;

	// register the starting position
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

	if (nodeGrid[gridPosition + moveUp].bIsWall == false && nodeGrid[gridPosition + moveUp].bIsExplored == false && gridPosition + moveUp > 0) moveValue += 1;

	if (nodeGrid[gridPosition + moveDown].bIsWall == false && nodeGrid[gridPosition + moveDown].bIsExplored == false && gridPosition + moveDown < gridSize) moveValue += 2;

	if (nodeGrid[gridPosition + moveLeft].bIsWall == false && nodeGrid[gridPosition + moveLeft].bIsExplored == false && gridPosition % mazeSizeX != 0 && gridPosition + moveLeft > 0) moveValue += 4;

	if (nodeGrid[gridPosition + moveRight].bIsWall == false && nodeGrid[gridPosition + moveRight].bIsExplored == false && (gridPosition + 1) % mazeSizeX != 0 && gridPosition + moveRight < gridSize) moveValue += 8;

	Evaluate();
}

int Mouse::RetrievePosition()
{
	return movementStack.Peek();
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
		std::cout << "Backing up";
		break;
	case 1: // move up
		gridPosition += moveUp;
		break;
	case 2: // move down
		gridPosition += moveDown;
		break;
	case 4: // move left
		gridPosition += moveLeft;
		break;
	case 8: // move right
		gridPosition += moveRight;
		break;
	default: // mouse can move in more than one direction
		break;
	}
#pragma endregion

#pragma region Two Directions
	switch (moveValue)
	{
	case 3: // move up and down
		gridPosition += PickRandomDirection(moveUp, moveDown, 0);
		break;
	case 5: // move up and left
		gridPosition += PickRandomDirection(moveUp, moveLeft, 0);
		break;
	case 9: // move up and right
		gridPosition += PickRandomDirection(moveUp, moveRight, 0);
		break;

	case 6: // move down and left
		gridPosition += PickRandomDirection(moveDown, moveLeft, 0);
		break;
	case 10: // move down and right
		gridPosition += PickRandomDirection(moveDown, moveRight, 0);
		break;

	case 12: // move left and right
		gridPosition += PickRandomDirection(moveLeft, moveRight, 0);
		break;

	default: // mouse can move in more than two directions
		break;
	}
#pragma endregion

#pragma region Three Directions
	switch (moveValue)
	{
	case 7: // move up, down and left
		gridPosition += PickRandomDirection(moveUp, moveDown, moveLeft);
		break;

	case 11: // move up, down and right
		gridPosition += PickRandomDirection(moveUp, moveDown, moveRight);
		break;

	case 13: // move up, left and right
		gridPosition += PickRandomDirection(moveUp, moveLeft, moveRight);
		break;

	case 14: // move down, left and right
		gridPosition += PickRandomDirection(moveDown, moveLeft, moveRight);
		break;

	default:
		break;
	}
#pragma endregion

	// push the new position to the stack
	movementStack.Push(gridPosition);
}

// pick a random direction to move in
int Mouse::PickRandomDirection(int const a, int const b, int const c = 0) // for some reason, the optional parameter doesn't work here
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, (2 + c != 0)); // Makes the max 2 or 3 based on the number of parameters passed. If c = 0, then Max = 2 + 0. Otherwise, Max = 2 + 1.

	switch (dis(gen))
	{
	case 1:
		return a;
	case 2:
		return b;
	case 3:
		return c;
	default:
		break;
	}
}