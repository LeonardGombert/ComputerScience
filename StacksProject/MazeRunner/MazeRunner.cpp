#include <iostream>
#include "Definitions.h"
#include "Stack.h"
#include "Grid.h"
#include "Mouse.h"

using namespace std;

int main()
{
	Stack stack;
	Grid grid = Grid("Maze.csv");
	Mouse mouse;

	while (mouse.RetrievePosition() != mazeEnd)
	{
		// check the top of the stack to get mouse position
		grid.DisplayGrid(mouse.RetrievePosition());

		cout << endl;
		cout << endl;

		system("PAUSE");
		system("CLS");

		mouse.CheckMoves(grid.RetrieveGrid());
	}

	cout << "Mouse found the exit !";
	
}