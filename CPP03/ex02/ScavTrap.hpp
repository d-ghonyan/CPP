#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap();
public:
	ScavTrap(std::string name);
	~ScavTrap();
	void guardGate(void);
	void attack(const std::string &target);
};