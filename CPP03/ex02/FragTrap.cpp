#include "FragTrap.hpp"

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << name << " says High five!\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	health = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap " << name << " constructor called!\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructor called!\n";
}

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << name << " attacks " << target << " with " << damage << " damage but now it's virtual!\n";
}