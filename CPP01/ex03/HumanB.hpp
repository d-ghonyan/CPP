#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon		*weapon = nullptr;
public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon weapon);
	void	attack();
};