#pragma once
#include "Node.h"
#include <vector>

class Grid
{
public:
	Grid(std::string file);
	~Grid();

	void DisplayGrid(int mousePosition);

	Node* RetrieveGrid();

private:
	std::vector<int> ReadCSV(std::string file);
	void GenerateGrid(std::vector<int> convertedMaze);

	int sizeY, sizeX;
	int start, end;

	Node *grid; // a pointer to a Node
};