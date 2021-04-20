#pragma once
template <typename T>
class Node
{
	Node(); // restricted constructor
	T* data;
	const int index;
public:
	Node(T*, const int&, Node<T>*); // constructor
	~Node() { puts("Default Destructor\n"); }
	T getData() { return *data; }
	Node<T>* previous;
	Node<T>* next;
};

template<typename T>
inline Node<T>::Node(T* data, const int& ind, Node<T>* prev)
	: data(data), index(ind), previous(prev), next(nullptr)
{
	if(prev != nullptr) prev->next = this; // if this isn't the first node
	prev = this; // set this new node as the tailPointer
}
