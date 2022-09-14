#pragma once

#include <iostream>

class	Weapon
{
private:
	std::string	type;
public:
	Weapon(std::string type);
	std::string	gettype();
	void		settype(std::string _type);
};