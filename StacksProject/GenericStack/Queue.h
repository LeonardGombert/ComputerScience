#pragma once
#include <stdarg.h>
template<typename T>
class Queue {
	const int queueSize = 100; // the circular array size
	T* queue = new T[queueSize];
	int front = 0, back = 0;
public:
	Queue() { ; } // default constructor
	Queue(const T, ...); // initializer list contructor
	Queue(Queue& rhs) { queue = rhs.getQueue(); } // copy constructor

	void UpdateCircle(); // make the array go full circle (needs fixing)
	
	void enqueue(T* item) { UpdateCircle(); queue[back++] = *(item); }
	void dequeue() { front++; }

	T& peek() const { return queue[front]; }
	T* getQueue() { return queue; }
};

template<typename T>
inline Queue<T>::Queue(const T count, ...)
{
	va_list ap; // argument pointer
	va_start(ap, count); // start the list count

	for (int i = 0; i < count; i++)
		this->enqueue(&va_arg(ap, T)); // increment through the arguments list
	
	va_end(ap); // free the memory
}

template<typename T>
inline void Queue<T>::UpdateCircle()
{
	if (back > queueSize) back = 0;
	if (front > queueSize) front = 0;
}
