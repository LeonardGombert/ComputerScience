#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include "DynamicArray.h"
#include "LinkedList.h"
using namespace LL;

int main()
{
	std::string str = "Hello";
	std::vector<std::string> v;

	// uses the push_back(const T&) overload, which means 
	// we'll incur the cost of copying str
	v.push_back(str);
	std::cout << "After copy, str is " << std::quoted(str) << '\n';

	// uses the rvalue reference push_back(T&&) overload, 
	// which means no strings will be copied; instead, the contents
	// of str will be moved into the vector.  This is less
	// expensive, but also means str might now be empty.
	v.push_back(std::move(str));
	std::cout << "After move, str is " << std::quoted(str) << '\n';

	std::cout << "The contents of the vector are " << quoted(v[0])
		<< ", " << quoted(v[1]) << '\n';
	std::cout << "There is " << v[0] << " at " << &(v[0]) << " in container #1." << std::endl;
	std::cout << "There is " << str << " at " << &str << std::endl;





	std::vector<int> v1 = { 1, 2, 3, 4, 5 };
	std::vector<int> v2 = { };

	std::cout << "There is " << v1[0] << " at " << &(v1[0]) << " in container #1." << std::endl;

	v2.push_back(std::move(v1[0])); // v1 is now empty, and v2 has contents of v1
	std::cout << "There is " << v1[0] << " at " << &(v1[0]) << " in container #1." << std::endl;
	std::cout << "There is " << v2[0] << " at " << &(v2[0]) << " in container #2." << std::endl;

	/*
#pragma region Linked List
	LinkedList<int> linkedList;
	linkedList.add(12);
	linkedList.add(57);
	linkedList.add(21);
	linkedList.add(902);

	std::cout << "First Value : " << linkedList.getFirst() << std::endl;
	std::cout << "Last Value : " << linkedList.getLast() << std::endl;
	std::cout << "Elements in List : " << linkedList.getCount() << std::endl;

	const int requestedValue = 1;
	std::cout << "You requested the value at position " << requestedValue << " : " << linkedList[requestedValue]->value << std::endl;
#pragma endregion

#pragma region DynamicArray
	/*DynamicArray<int> dynamic;
	dynamic.add(2);*/
#pragma endregion

}