#pragma once
namespace LL
{
	template<typename T>
	struct Node
	{
	private:
		Node() { ; } // restricted default constructor
	public:
		Node(const T, const int, Node<T>*); // move constructor
		Node(const Node<T>&& rhs); // copy constructor
		~Node() { printf("Node %d destroyed.\n", index); } // empty destructor 
		T value;
		int index;
		Node<T>* previous;
		Node<T>* next;
	};

	template<typename T>
	inline Node<T>::Node(const T val, const int i, Node<T>* last) : value(val), index(i), previous(last), next(nullptr)
	{
		puts("Move Constructor\n");
		if (last != nullptr) last->next = this; // if there is a previous node, make this current Node its next
		last = this; // regardless, set this as the last node
	}

	template<typename T>
	inline Node<T>::Node(const Node<T>&& rhs)
	{
		puts("Copy Constructor\n");
		value = rhs.value;
		index = rhs.index;
		previous = rhs.previous;
		next = rhs.next;
	}
}