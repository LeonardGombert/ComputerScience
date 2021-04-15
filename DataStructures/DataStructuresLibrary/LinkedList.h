#pragma once
template<typename N>
struct Node
{
private:
	Node(); // hidden default constructor
public:
	Node(N&& val, int i, Node<N>* prev);
	N value;
	int index;
	Node<N>* previous;
	Node<N>* next;
};

template<typename N>
inline Node<N>::Node(N&& val, const int i, Node<N>* prev) : value(val), index(i), previous(prev), next(nullptr) 
{
	if (prev != nullptr) prev->next = this; // if there is a previous node, make this current Node its next 
	else printf("This is the first Node in the List\n");
	prev = this;
}

template<typename T>
class LinkedList
{
private:
	int listSize = 0;
	Node<T>* startPointer = nullptr;
	Node<T>* tailPointer = nullptr;
public:
	LinkedList();
	void add(T&&) const; // rvalue reference for move semantics
	void remove(const int&)const;
	const int getCount();
	T* operator [] (const int&);
	T* getLast();
	T* getFirst();
};

template<typename T>
inline LinkedList<T>::LinkedList()
{
}

template<typename T>
inline void LinkedList<T>::add(T&& value) const
{
	// MOVE the original value into the Node, increment list size, and make the previous the tail pointer
	Node<T> newNode(std::move(value), listSize, tailPointer);
}

template<typename T>
inline void LinkedList<T>::remove(const int& index) const
{
}

template<typename T>
inline const int LinkedList<T>::getCount()
{
	return listSize;
}

template<typename T>
inline T* LinkedList<T>::operator[](const int& index)
{
	return &T();
}

template<typename T>
inline T* LinkedList<T>::getLast()
{
	return &T();
}

template<typename T>
inline T* LinkedList<T>::getFirst()
{
	return &T();
}