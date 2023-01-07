#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI(void) const
{
	std::cout << this->name << ", " << ClapTrap::name << "\n";
}

DiamondTrap::DiamondTrap(std::string _name): ClapTrap(_name + "_clap_name"),
	ScavTrap(_name), FragTrap(_name)
{
	health = FragTrap::health;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
	this->name = _name;
	std::cout << "DiamondTrap " << this->name << " constructor called!\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " destructor called!\n";
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}