#pragma once
template<typename T>
class Queue {
	const int queueSize = 4; // the circular array is of size 4
	T* queue = new T[queueSize];
	int front = 0, back = 0;
public:
	void checkCircle(); // make the array go full circle (needs fixing)
	void enqueue(T* item) { checkCircle(); queue[back++] = *(item); }
	void dequeue() { front++; }
	T& peek() const { return queue[front]; }
};// queue implementation should use a circular array to avoid having to shift everything "down"

template<typename T>
inline void Queue<T>::checkCircle()
{
	if (back > queueSize)
	{
		back = 0;		
		printf("The queue was full.\n");
	}
	if (front > queueSize) front = 0;
}
