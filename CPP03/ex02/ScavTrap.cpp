#include "ScavTrap.hpp"

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is guarding the gate!\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	health = 100;
	energy = 50;
	damage = 20;
	std::cout << "ScavTrap " << name << " constructor called!\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor called!\n";
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << name << " attacks " << target << " with " << damage << " damage but now it's virtual!\n";
}