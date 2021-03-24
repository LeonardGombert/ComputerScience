#pragma once
template<typename T>
class Queue {
	const int queueSize = 100;
	T* queue = new T[queueSize];
	int front = 0, back = 0;
public:
	void checkCircle() { if (back >= queueSize) back = 0; if (front >= queueSize) front = 0; } // make the array go full circle (needs fixing)
	void enqueue(T* item) { checkCircle(); queue[back++] = *(item); }
	void dequeue() { front++; }
	T& peek() const { return queue[front]; }
};// queue implementation should use a circular array to avoid having to shift everything "down"
