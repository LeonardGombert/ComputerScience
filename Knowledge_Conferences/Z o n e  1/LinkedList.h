#pragma once
#include "Node.h"
#include <cstdarg>

template<typename T>
class LinkedList
{
	int listSize = 0;
	Node<T>* startPointer = nullptr;
	Node<T>* tailPointer = nullptr;
public:
	LinkedList() { ; }
	~LinkedList() { ; }

	void add(T*);
	void remove(int&);
	int getCount() const;
	T getLast();
	T getFirst();

	Node<T>* operator [] (const int&) const;
};

template<typename T>
inline void LinkedList<T>::add(T* data)
{
	Node<T>* temp = new Node<T>(data, listSize, tailPointer);
	if (listSize++ == 0) startPointer = temp; // make this startPointer if first node
	tailPointer = temp; // make this tailPointer
}

template<typename T>
inline void LinkedList<T>::remove(int&)
{

}

template<typename T>
inline int LinkedList<T>::getCount() const
{
	return listSize;
}

template<typename T>
inline T LinkedList<T>::getLast()
{
	return tailPointer->data;
}

template<typename T>
inline T LinkedList<T>::getFirst()
{
	return startPointer->data;
}

template<typename T>
inline Node<T>* LinkedList<T>::operator[] (const int& index) const
{
	if (index < listSize)
	{
		Node<T>* nodeRef = startPointer;

		// determine whether to start at beginning or end of list
		if (index < listSize / 2)
		{
			nodeRef = startPointer;
			for (auto i = 0; i < index; i++) nodeRef = nodeRef->next;
		}
		else
		{
			nodeRef = tailPointer;
			for (auto i = 0; i < index; i++) nodeRef = nodeRef->previous;
		}

		return nodeRef;
	}

	else
	{
		puts("You reqested a value that doesn't exist. Try inputting a value within your List's range.\n");
		return nullptr;
	}
}
