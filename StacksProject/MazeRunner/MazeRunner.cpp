#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack stack;

	stack.Pop();

	cout << stack.Peek() << endl;
}