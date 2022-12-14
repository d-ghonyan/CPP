#pragma once
#include "Contact.hpp"

class Phonebook
{
private:
	int		len;
	Contact	contacts[8];
	int		isNumber(std::string s);
public:
	Phonebook();
	int		get_len();
	void	add(int *i);
	void	search();
};