#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string name);
	~FragTrap();
	void highFiveGuys(void);
	virtual	void attack(const std::string &target);
};