#include "Contact.hpp"
#include <iostream>

int	Contact::get_index()
{
	return index;
}

std::string Contact::get_fname()
{
	return fname;
}

std::string Contact::get_lname()
{
	return lname;
}

std::string Contact::get_nname()
{
	return nname;
}

std::string Contact::get_secret()
{
	return secret;
}

std::string Contact::get_number()
{
	return number;
}

void	Contact::set_index(int val)
{
	if (val >= 0 && val <= 7)
		index = val;
}

int	Contact::set_fname(std::string val)
{
	if (val == "")
	{
		std::cout << "Warning, empty first name";
		val = "empty";
	}
	else
		fname = val;
	return (0);
}

int	Contact::set_lname(std::string val)
{
	if (val == "")
	{
		std::cout << "Warning, empty last name";
		val = "empty";
	}
	else
		lname = val;
	return (0);
}

int	Contact::set_nname(std::string val)
{
	if (val == "")
	{
		std::cout << "Warning, empty nickname";
		val = "empty";
	}
	else
		nname = val;
	return (0);
}

int	Contact::set_secret(std::string val)
{
	if (val == "")
	{
		std::cout << "Warning, empty secret";
		val = "empty";
	}
	else
		secret = val;
	return (0);
}

int	Contact::set_number(std::string val)
{
	if (!isNumber(val))
		return (1);
	if (val == "")
	{
		std::cout << "Warning, empty number";
		val = "empty";
	}
	else
		number = val;
	return (0);
}

int		Contact::isNumber(std::string s)
{
	int	i = -1;
	while (s[++i])
		if (s[i] > '9' || s[i] < '0')
			return (0);
	return (1);
}
