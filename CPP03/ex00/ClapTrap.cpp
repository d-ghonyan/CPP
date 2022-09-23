#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name): health(10), energy(10), damage(0), name(_name)
{
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string& target)
{
	if (energy && health)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " << damage << " damage!\n"; 
		energy--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (energy && health)
	{
		std::cout << "ClapTrap " << name << " takes " << amount << " damage!\n";
		health = ((health - amount) > 0) ? (health - amount) : 0; 
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy && health)
	{
		std::cout << "ClapTrap " << name << " repairs " << amount << " health!\n";
		health += amount; 
		energy--;
	}
}