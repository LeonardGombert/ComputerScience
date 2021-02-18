#include <iostream>
#include "Stack.h"
#include "Grid.h"
#include "Mouse.h"
#include "MazeRunner.h"

using namespace std;

int main()
{
	Stack stack;
	Grid grid;
	Mouse mouse = Mouse(0, grid.gridSize); 

	while (true)
	{
		grid.DisplayGrid();

		cout << endl;
		cout << endl;

		system("PAUSE");
		system("CLS");

		mouse.Step(grid.RetrieveGrid()); // a reference to the original pointer
	}

	/*stack.Push(4);
	stack.Push(92);
	stack.Push(7);
	int yes = stack.Pop();
	cout << yes << endl;
	cout << stack.Peek() << endl;*/
}