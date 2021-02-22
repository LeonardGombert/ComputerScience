#include <iostream>
#include "Stack.h"
#include "Grid.h"
#include "Mouse.h"

using namespace std;

#define sizeX 6 
#define sizeY 5
#define startingPosition 0

int main()
{
	Stack stack;
	Grid grid = Grid(sizeX, sizeY, startingPosition);
	Mouse mouse = Mouse(sizeX, sizeY, startingPosition);

	while (true)
	{
		grid.DisplayGrid();

		cout << endl;
		cout << endl;

		system("PAUSE");
		system("CLS");

		mouse.CheckMoves(grid.RetrieveGrid());
	}
}