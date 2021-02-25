#pragma once
#include "Node.h"

class Grid
{
public:
	Grid(std::string file);
	~Grid();

	void DisplayGrid(int mousePosition);

	Node* RetrieveGrid();

private:
	void ReadCSV();
	void GenerateGrid();
	
	std::string fileName;

	Node *grid; // a pointer to a Node
};