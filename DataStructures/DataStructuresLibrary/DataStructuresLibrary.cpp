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
	std::vector<std::string> v1 = { "one", "two", "three", "four", "five" };
	std::vector<std::string> v2 = { "six", "seven", "eight", "nine", "ten" };

	auto v3 = std::move(v2);

	std::cout << v2.size() << std::endl;
	std::cout << v3.size() << std::endl;

	int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int y[10] = { };

	y = std::move(x);

	std::cout << x << std::endl;
	std::cout << y << std::endl;

	double val = 12;
	std::cout << val << std::endl;

#pragma region Linked List
	/*LinkedList<int> linkedList;
	linkedList.add(12);
	linkedList.add(57);
	linkedList.add(21);
	linkedList.add(902);

	std::cout << "First Value : " << linkedList.getFirst() << std::endl;
	std::cout << "Last Value : " << linkedList.getLast() << std::endl;
	std::cout << "Elements in List : " << linkedList.getCount() << std::endl;

	const int requestedValue = 1;
	std::cout << "You requested the value at position " << requestedValue << " : " << linkedList[requestedValue]->value << std::endl;*/
#pragma endregion

#pragma region DynamicArray
	/*DynamicArray<int> dynamic;
	dynamic.add(2);*/
#pragma endregion
	return 0;
}