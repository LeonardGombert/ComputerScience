#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main()
{
	Stack<int> stack;
	stack.push(new int(4));
	stack.push(new int(5));
	stack.push(new int(6));
	stack.push(new int(7));

	printf("The top-most item of the stack is %d.\n", stack.peek());
	stack.pop();
	stack.pop();
	printf("After popping twice : %d.\n", stack.peek());


	Queue<int> queue;
	queue.enqueue(new int(4));
	queue.enqueue(new int(5));
	queue.enqueue(new int(6));
	queue.enqueue(new int(7));
	queue.enqueue(new int(8));
	queue.enqueue(new int(9));
	queue.enqueue(new int(10));

	printf("The oldest-item of the queue is %d.\n", queue.peek());

	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();

	printf("The oldest-item of the queue after three dequeues is %d.\n", queue.peek());

	return 0;
}