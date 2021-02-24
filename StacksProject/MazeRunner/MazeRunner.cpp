#include <iostream>
#include "Stack.h"
#include "Grid.h"
#include "Mouse.h"

using namespace std;

#define sizeX 6
#define sizeY 5
#define startingPosition 0
#define exit 24

int main()
{
	Stack stack;
	Grid grid = Grid(sizeX, sizeY, startingPosition, exit);
	Mouse mouse = Mouse(sizeX, sizeY, startingPosition);

	while (mouse.movementStack.Peek() != grid.exitNode)
	{
		grid.DisplayGrid(mouse.movementStack.Peek());

		cout << endl;
		cout << endl;

		system("PAUSE");
		system("CLS");

		mouse.CheckMoves(grid.RetrieveGrid());
	}

	cout << "Mouse found the exit !";
	
}