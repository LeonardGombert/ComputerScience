#include <iostream>
#include "LinkedList.h"

int main()
{
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
}