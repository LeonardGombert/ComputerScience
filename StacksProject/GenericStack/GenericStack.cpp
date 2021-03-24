#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int> stack;
	stack.push(new int(4));
	stack.push(new int(5));
	stack.push(new int(6));
	stack.push(new int(7));

	printf("The top-most item is %d.\n", stack.peek());
	stack.pop();
	stack.pop();
	printf("The top-most item is %d.\n", stack.peek());

	return 0;
}