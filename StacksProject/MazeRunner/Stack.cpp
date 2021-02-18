#include "Stack.h"
#include <stdio.h>
#include <string.h>

Stack::Stack()
{
	currentSize = 1;
	stack = new int[currentSize] {0};
	tailPointer = stack[0];
}

Stack::~Stack()
{
	delete[]stack;
}

void Stack::Push(int x)
{
	if (tailPointer >= currentSize)
	{
		Resize();
		Push(x);
	}

	else
	{
		stack[tailPointer] = x;
		tailPointer++;
	}
}

int Stack::Pop()
{
	return stack[--tailPointer];
}

void Stack::Resize()
{
	size_t newSize = currentSize * 2;
	int* newStack = new int[newSize];

	// define the new array destination, and copy contents of original array, defining how many numbers you must copy
	memcpy(newStack, stack, currentSize * sizeof(int));

	currentSize = newSize;
	
	// delete the memory pointed by the stack, and reassign it
	delete[]stack; 
	stack = newStack;
}