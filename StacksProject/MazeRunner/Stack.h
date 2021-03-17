#pragma once
class Stack
{
public:
	Stack();
	~Stack();

	void Push(int x);
	void Pop();
	int Peek();

	const int& size() { return tailPointer; }
	
private:
	void Resize();

	int* stack;
	int currentSize; // the dimension of the Stack
	int tailPointer; // how many items are currently in the Stack
};