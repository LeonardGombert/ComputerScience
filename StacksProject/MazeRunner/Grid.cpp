#include <iostream>
#include "Grid.h"
#include "Node.h"

using namespace std;

#define sizeX 6 
#define sizeY 5

Grid::Grid()
{
	grid = new Node[sizeX * sizeY];
	GenerateGrid();
}

Grid::~Grid()
{
}

void Grid::GenerateGrid()
{
	grid[1].bWall = grid[3].bWall = grid[5].bWall = grid[7].bWall = grid[15].bWall = grid[16].bWall
	= grid[18].bWall = grid[19].bWall = grid[20].bWall = grid[21].bWall = grid[29].bWall = true;

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			grid[i*sizeX +j].index = i;
			
			if(grid[i * sizeX + j].bWall == true) cout<< "x ";
			else cout<< "o ";
		}
		cout << endl;
	}
}
