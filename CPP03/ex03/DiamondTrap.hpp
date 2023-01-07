#pragma once

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
	DiamondTrap();
public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	void whoAmI(void) const ;
	void attack(const std::string &target);
};