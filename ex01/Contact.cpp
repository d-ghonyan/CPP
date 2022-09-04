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
	return fname;
}

std::string Contact::get_nname()
{
	return fname;
}

std::string Contact::get_secret()
{
	return fname;
}

std::string Contact::get_number()
{
	return fname;
}

void		Contact::set_index(int val)
{
	if (val >= 0 && val <= 7)
		index = val;
}

void		Contact::set_fname(std::string val)
{
	if (val == "")
	{
		std::cout << "Warning, empty first name";
		val = "empty";
	}
	else
		fname = val;
}

void		Contact::set_lname(std::string val)
{
	if (val == "")
	{
		std::cout << "Warning, empty last name";
		val = "empty";
	}
	else
		lname = val;
}

void		Contact::set_nname(std::string val)
{
	if (val == "")
	{
		std::cout << "Warning, empty nickname";
		val = "empty";
	}
	else
		nname = val;
}

void		Contact::set_secret(std::string val)
{
	if (val == "")
	{
		std::cout << "Warning, empty secret";
		val = "empty";
	}
	else
		secret = val;
}

void		Contact::set_number(std::string val)
{
	if (val == "")
	{
		std::cout << "Warning, empty number";
		val = "empty";
	}
	else
		number = val;
}