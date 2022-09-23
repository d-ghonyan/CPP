#pragma once

#include <iostream>

class ClapTrap
{
private:
	int			energy;
	int			health;
	int			damage;
	std::string	name;
	ClapTrap();
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
