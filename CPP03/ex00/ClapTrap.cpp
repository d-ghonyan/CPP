#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name): health(10), energy(10), damage(0), name(_name)
{
	std::cout << "ClapTrap " << name << " constructor called!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	name = other.name;
	health = other.health;
	energy = other.energy;
	damage = other.damage;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called!\n";
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called!\n";
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
		health = (((health > amount)) ? (health - amount) : 0);
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