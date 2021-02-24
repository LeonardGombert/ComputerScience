#include <iostream>
#include "Definitions.h"
#include "Stack.h"
#include "Grid.h"
#include "Mouse.h"

using namespace std;



int main()
{
	Stack stack;
	Grid grid;
	Mouse mouse;

	while (mouse.movementStack.Peek() != mazeEnd)
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