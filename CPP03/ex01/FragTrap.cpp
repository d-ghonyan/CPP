#include "FragTrap.hpp"

void FragTrap::highFiveGuys(void)
{
	std::cout << "High five!\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	health = 100;
	energy = 100;
	damage = 30;
	std::cout << "Default constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "Default destructor called\n";
}
