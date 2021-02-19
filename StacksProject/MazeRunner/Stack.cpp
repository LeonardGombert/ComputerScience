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
	// if the tailPointer is already at the last available position...
	if (tailPointer == (currentSize - 1))
	{
		Resize();
		Push(x);
	}

	else
	{
		// move the tailPointer up by one and add a value
		tailPointer++;
		stack[tailPointer] = x;
	}
}

int Stack::Pop()
{
	if (tailPointer == stack[0]) return printf("Stack was empty");
	
	// return the last value and move the tail pointer down
	else return stack[tailPointer--];
	
}

int Stack::Peek()
{
	return stack[tailPointer];
}

void Stack::Resize()
{
	int newSize = currentSize * 2;
	int* newStack = new int[newSize];

	// define the new array destination, and copy contents of original array, defining how many numbers you must copy
	memcpy(newStack, stack, currentSize * sizeof(int));

	currentSize = newSize;

	// delete the memory pointed by the stack, and reassign it
	delete[]stack;
	stack = newStack;
}