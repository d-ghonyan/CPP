#include "ScavTrap.hpp"

void ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << name << " is guarding the gate!\n";
}

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name)
{
	health = 100;
	energy = 50;
	damage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called!\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destructor called!\n";
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << this->name << " attacks " << target << " with " << damage << " damage but now it's virtual!\n";
}