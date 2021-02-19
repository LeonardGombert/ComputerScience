#include <iostream>
#include "Stack.h"
#include "Grid.h"
#include "Mouse.h"

using namespace std;

#define sizeX 6 
#define sizeY 5
#define startingPosition 12

int main()
{
	Stack stack;
	Grid grid = Grid(sizeX, sizeY, startingPosition);
	Mouse mouse = Mouse(startingPosition, sizeX, sizeY);

	while (true)
	{
		grid.DisplayGrid();

		cout << endl;
		cout << endl;

		system("PAUSE");
		system("CLS");

		cout << mouse.CheckMoves(grid.RetrieveGrid()); // a reference to the original pointer
	}
}