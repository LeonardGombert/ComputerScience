#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main()
{
	Queue<int> queue;
	queue.enqueue(new int(4));
	queue.enqueue(new int(5));
	queue.enqueue(new int(6));
	queue.enqueue(new int(7));
	queue.enqueue(new int(8));
	queue.enqueue(new int(9));
	queue.enqueue(new int(10));

	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	printf("The oldest-item of the queue after three dequeues is %d.\n", queue.peek());

	return 0;
}