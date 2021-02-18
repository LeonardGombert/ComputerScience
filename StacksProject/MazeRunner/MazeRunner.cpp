#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack myStack;

	for (size_t i = 0; i <= 64; i++)
	{
		myStack.Push(i);
	}

	myStack.Pop();
	myStack.Pop();
	myStack.Pop();
	myStack.Pop();

	cout << myStack.stack[--myStack.tailPointer] << endl;
}