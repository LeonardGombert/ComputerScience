#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "Definitions.h"
#include "Grid.h"
#include "Node.h"

using namespace std;

// create the maze and define contents
Grid::Grid(std::string file)
{
	GenerateGrid(ReadCSV(file));
}

Grid::~Grid()
{
	delete[]grid;
}


std::vector<int> Grid::ReadCSV(std::string file)
{
	std::vector<int> convertedMaze;
	std::ifstream mazeFile(file);

	std::string line;
	int val;

	if (!mazeFile.is_open()) std::cout << "Couldn't open the file";//throw std::runtime_error("Couldn't open the file");

	else
	{
		while (std::getline(mazeFile, line))
		{
			// Create a stringstream of the current line
			std::stringstream ss(line);

			// Keep track of the current column index

			// Extract each integer
			while (ss >> val) {

				// Add the current integer to the 'colIdx' column's values vector
				convertedMaze.push_back(val);

				// If the next token is a comma, ignore it and move on
				if (ss.peek() == ',') ss.ignore();
			}

			sizeY++; // increment the number of lines
		}
		mazeFile.close();
	}

	std::vector<int>::size_type sz = convertedMaze.size();

	sizeY--; // - 1 because the last line also contains a line break
	sizeX = sz / sizeY; // get the number of items per line

	return convertedMaze;
}

void Grid::GenerateGrid(std::vector<int> convertedMaze)
{
	grid = new Node[sizeX * sizeY]; // create grid of Nodes

	std::cout << "The grid array is of size " << sizeX*sizeY << endl;
	std::cout << "The vector is of size " << convertedMaze.size() << endl;

	for (unsigned int i = 0; i < sizeX*sizeY; i++)
	{
		grid[i].bIsWall = (convertedMaze[i] == 1) ? true : false;
		if (convertedMaze[i] == 2) start = i;
		if (convertedMaze[i] == 3) end = i;
	}

	grid[end].bIsEnd = true;
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
		else cout << ": ";
	}
}

// return the contents of the grid pointer
Node* Grid::RetrieveGrid()
{
	return grid;
}