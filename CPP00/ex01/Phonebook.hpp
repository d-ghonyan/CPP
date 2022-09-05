#pragma once
#include "Contact.hpp"

class Phonebook
{
private:
	int		isNumber(std::string s);
	int		len;
	Contact	contacts[8];
public:
	Phonebook();
	int		get_len();
	void	add(int *i);
	void	search();
};