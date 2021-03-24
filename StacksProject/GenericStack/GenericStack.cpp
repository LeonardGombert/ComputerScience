#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include "Stack.h"
#include "Queue.h"

int main()
{
	/*
	std::deque<const char*> students = { "Tom", "Minnie", "Doo-rag", "Ass-Bone", "Critical Hit", "Cement Mixer" };
	std::queue<const char*, std::deque<const char*>> queue(students);

	std::deque<int> trays;
	std::stack<int, std::deque<int>> stack(trays);

	queue.pop();
	stack.push(1);
	queue.pop();
	stack.push(1);
	printf("The first student in line is %s. The stack of trays is %d high.\n", queue.front(), stack.size());
	*/

	Queue<int> queue;
	Queue<int> queue;
	queue.dequeue();
	queue.dequeue();
	std::cout << queue.peek();

	return 0;
}