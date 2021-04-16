#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include "Stack.h"
#include "Queue.h"

int main()
{
	Queue<int> queue;
	Queue<const char*> stringQueue("Tom", "Minnie", "Doo-rag", "Ass-Bone", "Critical Hit", "Cement Mixer"); // variadic argument constructor
	queue.dequeue();
	queue.dequeue();
	std::cout << queue.peek();

	return 0;
}