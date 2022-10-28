#pragma once

#include <iostream>

class ClapTrap
{
private:
	unsigned int	health;
	unsigned int	energy;
	unsigned int	damage;
	std::string		name;
	ClapTrap();
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
