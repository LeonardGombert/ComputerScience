#pragma once
class Stack
{
public:
	Stack();
	~Stack();

	void Push(int x);
	int Pop();
	int Peek();
	
private:
	void Resize();

	int* stack;
	int currentSize;
	int tailPointer;
};