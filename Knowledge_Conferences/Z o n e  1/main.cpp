#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include "LinkedList.h"

template<typename T>
void display(T disp) { std::cout << disp << std::endl; }

int main()
{	
	LinkedList<int> linkedList;
	linkedList.add(new int(4));
	linkedList.addV(3, 12, 23, 34, nullptr);

	display(linkedList.getCount());
	display(linkedList[2]->getData());
}