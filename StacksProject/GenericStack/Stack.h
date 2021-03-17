#pragma once

#include <stdio.h>
#include <string.h>
#include <iostream>

template <typename T>
class Stack
{
public:
	Stack();
	~Stack();

	void push(T* object); // pointer, because don't pass large obj in functions
	T pop(); // reference, because we want to get the original object, not a copy 
	T& peek()const { return stackPtr[stackTail - 1]; };
	int getsize() const { return stackSize; }

private:
	void resize();

	T* stackPtr = new T[1]; // create an array with only one slot

	int stackSize = 100; // size of the array
	int stackTail = 0; // points to the last unoccupied position
};

template<typename T>
inline Stack<T>::Stack()
{
}

template<typename T>
inline Stack<T>::~Stack()
{
}

template<typename T>
inline void Stack<T>::push(T* object)
{
	if (++stackTail >= stackSize) resize();
	stackPtr[stackTail - 1] = *object;
	printf("pushing %d\n", *object);
}

template<typename T>
inline T Stack<T>::pop()
{
	return stackPtr[--stackTail];
}

template<typename T>
inline void Stack<T>::resize()
{
	std::cout << "Resizing";

	stackSize *= 2;
	T* newStackPtr = new T[stackSize];
	memcpy(newStackPtr, stackPtr, sizeof(stackPtr));
	stackPtr = newStackPtr;
	delete[] newStackPtr; // delete the newly create stack
}
