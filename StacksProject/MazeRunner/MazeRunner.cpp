#include <iostream>
#include "Stack.h"
#include "Grid.h"
#include "Mouse.h"

using namespace std;

int main()
{
	Grid grid = Grid("Maze.csv");
	Mouse mouse = Mouse(grid.sizeX(), grid.sizeY(), grid.start());

	while (mouse.RetrievePosition() != grid.end())
	{
		// check the top of the stack to get mouse position
		grid.DisplayGrid(mouse.RetrievePosition());

		cout << endl;
		cout << endl;

		system("PAUSE");
		system("CLS");

		mouse.CheckMoves(grid.nodeGrid());
	}

	cout << "Mouse found the exit !";
	
}