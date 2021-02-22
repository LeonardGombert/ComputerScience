#include <iostream>
#include "Grid.h"
#include "Node.h"

using namespace std;

Grid::Grid(int x, int y, int z)
{
	sizeX = x;
	sizeY = y;
	startingPos = z;

	grid = new Node[sizeX * sizeY]; // create grid of Nodes
	GenerateGrid();
}

Grid::~Grid()
{
}

void Grid::DisplayGrid()
{
	for (int i = 0; i < sizeX * sizeY; i++)
	{
		if (i % sizeX == 0) cout << endl;
		
		if (grid[i].bWall) cout << "x ";
		else if (grid[i].mouse) cout << "O ";
		else if (grid[i].explored) cout << "o ";
		else cout << ". ";
	}
}

Node* Grid::RetrieveGrid()
{
	return grid; // return the contents of the pointer
}

// create the maze and define contents
void Grid::GenerateGrid()
{
	grid[startingPos].mouse = true;

	grid[1].bWall = grid[3].bWall = grid[5].bWall = grid[7].bWall = grid[15].bWall = grid[16].bWall
	= grid[18].bWall = grid[19].bWall = grid[20].bWall = grid[21].bWall = grid[29].bWall = true;
}
