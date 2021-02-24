#include <iostream>
#include "Definitions.h"
#include "Grid.h"
#include "Node.h"

using namespace std;

// create the maze and define contents
Grid::Grid()
{
	grid = new Node[mazeSizeX * mazeSizeY]; // create grid of Nodes
	
	grid[24].bIsEnd = true;

	// 10 x 10 grid maze
	/*grid[1].bIsWall = grid[3].bIsWall = grid[4].bIsWall = grid[5].bIsWall = grid[7].bIsWall = grid[11].bIsWall = grid[17].bIsWall = grid[19].bIsWall =
	grid[23].bIsWall = grid[25].bIsWall = grid[27].bIsWall = grid[29].bIsWall = grid[30].bIsWall = grid[31].bIsWall = grid[32].bIsWall = grid[33].bIsWall =
	grid[35].bIsWall = grid[39].bIsWall = grid[42].bIsWall = grid[43].bIsWall = grid[45].bIsWall = grid[46].bIsWall = grid[49].bIsWall = grid[50].bIsWall =
	grid[56].bIsWall = grid[60].bIsWall = grid[61].bIsWall = grid[63].bIsWall = grid[64].bIsWall = grid[71].bIsWall = grid[73].bIsWall = grid[74].bIsWall =
	grid[76].bIsWall = grid[77].bIsWall = grid[78].bIsWall = grid[79].bIsWall = grid[86].bIsWall = grid[87].bIsWall = grid[90].bIsWall = grid[91].bIsWall =
	grid[93].bIsWall = true;*/

	//6 x 5 grid maze
	grid[1].bIsWall = grid[3].bIsWall = grid[5].bIsWall = grid[7].bIsWall = grid[15].bIsWall = grid[16].bIsWall =
		grid[18].bIsWall = grid[19].bIsWall = grid[20].bIsWall = grid[21].bIsWall = grid[29].bIsWall = true;
}

Grid::~Grid()
{
	delete[]grid;
}

void Grid::DisplayGrid(int mousePosition)
{
	for (int i = 0; i < mazeSizeX * mazeSizeY; i++)
	{
		if (i % mazeSizeX == 0) cout << endl;

		if (grid[i].bIsWall) cout << "# ";
		else if (i == mousePosition) cout << "M ";
		else if (grid[i].bIsExplored) cout << ". ";
		else if (grid[i].bIsEnd) cout << "E ";
		else cout << "  ";
	}
}

// return the contents of the grid pointer
Node* Grid::RetrieveGrid() 
{ 
	return grid; 
}