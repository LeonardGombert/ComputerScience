#pragma once
class Node
{
public:
	Node();
	~Node();

	bool bIsExplored;
	bool bIsWall; 
	bool bIsBranching; // does the path branch out ? 
};

