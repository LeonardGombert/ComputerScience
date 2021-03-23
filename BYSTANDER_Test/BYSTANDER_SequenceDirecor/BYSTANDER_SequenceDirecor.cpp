#include <iostream>
#include "SequenceDirector.h"

// by default, initialize the singleton to be null outside of class definition
SequenceDirector* SequenceDirector::instance = NULL;

int main()
{
	SequenceDirector::LazyInititalizeSingleton(1);

	while (true)
	{
		int choice;
		std::cout << "Select a time direction : ";
		std::cin >> choice;

		if (choice == 1)
		{
			SequenceDirector::getinstance()->StartSequence();
			std::cout << "Moving Forward" << std::endl;
			while (SequenceDirector::getinstance()->MoveTime())
			{

			}
			std::cout << "Made it to the end" << std::endl;
		}

		else if (choice == 2)
		{
			SequenceDirector::getinstance()->StartSequence();

			std::cout << "Rewinding Time" << std::endl;
			while (SequenceDirector::getinstance()->MoveTime())
			{

			}
			std::cout << "Made it to the beginning" << std::endl;
		}
	}

	return 0;
}
