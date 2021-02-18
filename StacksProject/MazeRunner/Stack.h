#pragma once
class Stack
{
public:
	Stack();
	~Stack();

	void Push(int x);
	int Pop();
	int Peek();
	int *stack;
	
private:
	void Resize();
	int currentSize;
	int tailPointer;
};