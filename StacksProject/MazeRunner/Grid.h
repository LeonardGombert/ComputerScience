#pragma once
#include "Node.h"
#include <vector>

class Grid
{
public:
	Grid(std::string file);
	~Grid();

	void DisplayGrid(int mousePosition);

	Node* nodeGrid() { return _grid; }
	const int& sizeY() { return _sizeY; }
	const int& sizeX() { return _sizeX; }
	const int& start() { return _start; }
	const int& end() { return _end; }

private:
	std::vector<int> ReadCSV(std::string file);
	void GenerateGrid(std::vector<int> convertedMaze);

	int _sizeY, _sizeX;
	int _start, _end;

	Node* _grid; // a pointer to a Node
};