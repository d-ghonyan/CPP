#include <iostream>
#include <iomanip>
#include "Phonebook.hpp"
#include "Contact.hpp"

int		Phonebook::isNumber(std::string s)
{
	int	i = -1;
	while (s[++i])
		if (s[i] > '9' || s[i] < '0')
			return (0);
	return (1);
}

Phonebook::Phonebook() : len(0) {}

int	Phonebook::get_len() { return len; }

void	Phonebook::add(int *i)
{
	int			err = 0;
	int			j = 0;
	std::string	commands[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
	std::string	val;

	if (*i > 7)
		*i = 0;
	while (j < 5)
	{
		std::cout << commands[j] << ":\n";
		std::cin >> val;
		switch (j)
		{
		case 0:
			err = contacts[*i].set_fname(val);
			break ;
		case 1:
			err = contacts[*i].set_lname(val);
			break ;
		case 2:
			err = contacts[*i].set_nname(val);
			break ;
		case 3:
			err = contacts[*i].set_number(val);
			break ;
		case 4:
			err = contacts[*i].set_secret(val);
			break ;
		}
		if (!err)
		{
			j++;
			contacts[*i].set_index(*i);
		}
	}
	if (len < 8)
		len++;
}

void	Phonebook::search()
{
	int			i = -1;
	std::string	index;

	while (++i < len)
	{
		std::cout << std::right << std::setw(10) << contacts[i].get_index() << " |";
		std::cout << std::right << std::setw(10) << contacts[i].get_fname().substr(0, 9) << ((contacts[i].get_fname().length() > 9) ? "." : "") << " |";
		std::cout << std::right << std::setw(10) << contacts[i].get_lname().substr(0, 9) << ((contacts[i].get_lname().length() > 9) ? "." : "") << " |";
		std::cout << std::right << std::setw(10) << contacts[i].get_nname().substr(0, 9) << ((contacts[i].get_nname().length() > 9) ? "." : "") << " |" << "\n";
	}
	i = 0;
	while (1)
	{
		std::cout << "Enter the index: ";
		std::cin >> index;
		if (!this->isNumber(index)
			|| index.length() > 2 || (std::stoi(index) > 7)
			|| std::stoi(index) > len - 1)
			std::cout << "\x1b[31mInvallid argument\x1b[0m\n";
		else
		{
			std::cout << "First name: " << contacts[std::stoi(index)].get_fname() << std::endl;
			std::cout << "Last name: " << contacts[std::stoi(index)].get_lname() << std::endl;
			std::cout << "Nickname: " << contacts[std::stoi(index)].get_nname() << std::endl;
			std::cout << "Number: " << contacts[std::stoi(index)].get_number() << std::endl;
			std::cout << "Darkest Secret: " << contacts[std::stoi(index)].get_secret() << std::endl;
			break ;
		}
	}
}
