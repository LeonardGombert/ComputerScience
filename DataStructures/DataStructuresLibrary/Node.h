#pragma once
namespace LL
{
	template<typename T>
	struct Node
	{
	private:
		Node() { ; } // restricted default constructor
	public:
		Node(T&, const int, Node<T>*) noexcept; // move constructor
		Node(const Node<T>& rhs); // copy constructor
		~Node() { printf("Node %d destroyed.\n", index); } // empty destructor 
		T value;
		int index;
		Node<T>* previous;
		Node<T>* next;
	};

	// Move Constructor 
	template<typename T>
	inline Node<T>::Node(T& val, const int i, Node<T>* tailPtr) noexcept 
		: index(i), previous(tailPtr), next(nullptr)
	{
		printf("Move Constructor\n");
		
		value = std::move(val);

		if (tailPtr != nullptr) tailPtr->next = this; // if there previously was a TailPointer Node, make this its "Next" Node
		tailPtr = this; // set this new node as the current TailPointer
	}

	// don't know why I made this
	template<typename T>
	inline Node<T>::Node(const Node<T>& rhs)
	{
		puts("Copy Constructor\n");
		value = rhs.value;
		index = rhs.index;
		previous = rhs.previous;
		next = rhs.next;
	}
}