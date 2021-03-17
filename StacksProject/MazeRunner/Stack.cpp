#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Stack.h"

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

	// move the tailPointer up by one and add the value
	else stack[++tailPointer] = x;
}

void Stack::Pop()
{
	if (tailPointer == stack[0]) std::cout << ">> Stack was empty <<" << std::endl;
	
	else
	{
		// remove the last element and decrement the tail pointer
		stack[tailPointer--] = 0;
		std::cout << ">> Stack Popped <<" << std::endl;
	}
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