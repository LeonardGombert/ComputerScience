#pragma once
#include "Node.h"
namespace LL
{
	template<typename T>
	class LinkedList
	{
	private:
		int listSize;
		Node<T>* startPointer;
		Node<T>* tailPointer;
	public:
		LinkedList();
		~LinkedList();
		void add(const T&&); // rvalue reference for move semantics
		void remove(const int&);
		int getCount() const;
		T getLast();
		T getFirst();

		Node<T>* operator [] (const int&) const;
	};

	template<typename T>
	inline LinkedList<T>::LinkedList() : listSize(0), startPointer(nullptr), tailPointer(nullptr) { ; }

	template<typename T>
	inline LinkedList<T>::~LinkedList()
	{
		Node<T>* nodeRef = startPointer;

		for (auto i = 1; i < listSize; i++)
		{
			nodeRef = nodeRef->next;
			delete nodeRef->previous;
		}

		delete tailPointer;
	}

	template<typename T>
	inline void LinkedList<T>::add(const T&& value)
	{
		printf("1 : Value %d is at %p\n", value, &value);
		// MOVE the original value into the Node + give it an index + make the previous the tail pointer
		Node<T>* newNode = new Node<T>(std::move(value), listSize, tailPointer);
		printf("2 : Value %d is at %p\n", value, &value);
		if (listSize++ == 0) startPointer = newNode;
		tailPointer = newNode;
	}

	template<typename T>
	inline void LinkedList<T>::remove(const int& index)
	{
		Node<T>* nodeRef = this->operator[](index);

		if (nodeRef->next != nullptr) nodeRef->next->previous = nodeRef->previous; // link the next node to the previous node
		if (nodeRef->previous != nullptr) nodeRef->previous->next = nodeRef->next; // link the previous node to the next node

		delete nodeRef; // delete the target node from memory
		printf("Removed element at position %d.\n", index);

		listSize--;
	}

	template<typename T>
	inline int LinkedList<T>::getCount() const
	{
		return listSize;
	}

	template<typename T>
	inline T LinkedList<T>::getLast()
	{
		return tailPointer->value;
	}

	template<typename T>
	inline T LinkedList<T>::getFirst()
	{
		return startPointer->value;
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
}