#include <iostream>
#include "Grid.h"
#include "Node.h"

using namespace std;

#define sizeX 6 
#define sizeY 5

Grid::Grid()
{
	grid = new Node[sizeX * sizeY];
	gridSize = sizeX * sizeY;
	GenerateGrid();
}

Grid::~Grid()
{
}

void Grid::DisplayGrid()
{
	for (size_t i = 0; i < sizeX * sizeY; i++)
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

void Grid::GenerateGrid()
{
	grid[0].mouse = true;

	grid[1].bWall = grid[3].bWall = grid[5].bWall = grid[7].bWall = grid[15].bWall = grid[16].bWall
	= grid[18].bWall = grid[19].bWall = grid[20].bWall = grid[21].bWall = grid[29].bWall = true;

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			grid[i*sizeX +j].index = i;
		}
	}
}
