#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	FragTrap();
public:
	FragTrap(std::string name);
	~FragTrap();
	void highFiveGuys(void) const ;
	void attack(const std::string &target);
};