#include <iomanip>
#include <iostream>
#include "Contact.hpp"
#include "Phonebook.hpp"

int	main()
{
	int			i = 0;
	Phonebook	phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (command == "ADD")
		{
			phonebook.add(&i);
			i++;
		}
		else if (command == "SEARCH" && i)
			phonebook.search();
		else if (command == "EXIT")
			return (0);
	}
}