#pragma once
template<typename T>
class Stack {
	T* stack = new T[100];
	int back = 0; // the stack's tail pointer
public:
	void push(T* item) { stack[++back] = *(item); }
	void pop() { back--;}
	T& peek() const { return stack[back]; }
};