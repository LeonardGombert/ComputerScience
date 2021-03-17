#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int> stack;
	int x = 4;
	stack.push(&x);
	x++;
	stack.push(&x);
	x++;
	stack.push(&x);
	x++;
	stack.push(&x);

	printf("The top-most item is %d.\n", stack.peek());

	const int& reference = stack.pop();
	stack.pop();
	stack.pop();

	printf("The top-most item is %d.\n", stack.peek());
	printf("My reference is %d.\n", reference);

	return 0;
}