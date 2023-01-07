#include "FragTrap.hpp"

void FragTrap::highFiveGuys(void)  const 
{
	std::cout << "FragTrap " << name << " says High five!\n";
}

FragTrap::FragTrap(std::string _name): ClapTrap(_name)
{
	health = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap " << this->name << " constructor called!\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " destructor called!\n";
}

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << this->name << " attacks " << target << " with " << damage << " damage but now it's virtual!\n";
}