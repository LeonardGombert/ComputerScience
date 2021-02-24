#include <iostream>
#include "Grid.h"
#include "Node.h"

using namespace std;

Grid::Grid(int x, int y, int z, int w)
{
	sizeX = x;
	sizeY = y;
	startNode = z;
	exitNode = w;

	grid = new Node[sizeX * sizeY]; // create grid of Nodes
	GenerateGrid();
}

Grid::~Grid()
{
}

void Grid::DisplayGrid(int mousePosition)
{
	for (int i = 0; i < sizeX * sizeY; i++)
	{
		if (i % sizeX == 0) cout << endl;
		
		if (grid[i].bIsWall) cout << "# ";
		else if (i == mousePosition) cout << "M ";
		else if (grid[i].bIsExplored) cout << ". ";
		else if (grid[i].bIsEnd) cout << "E ";
		else cout << "  ";
	}
}

// return the contents of the grid pointer
Node* Grid::RetrieveGrid() { return grid; }

// create the maze and define contents
void Grid::GenerateGrid()
{
	grid[exitNode].bIsEnd = true;

	grid[1].bIsWall = grid[3].bIsWall = grid[5].bIsWall = grid[7].bIsWall = grid[15].bIsWall = grid[16].bIsWall
	= grid[18].bIsWall = grid[19].bIsWall = grid[20].bIsWall = grid[21].bIsWall = grid[29].bIsWall = true;
}
