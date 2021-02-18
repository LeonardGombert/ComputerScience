#pragma once
class Stack
{
public:
	Stack();
	~Stack();

	void Push(int x);
	int Pop();
	int *stack;
	
	int currentSize;
	int tailPointer;

private:
	void Resize();
};