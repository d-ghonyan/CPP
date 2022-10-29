#pragma once

#include <iostream>

class ClapTrap
{
protected:
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
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	virtual void attack(const std::string& target);
};
