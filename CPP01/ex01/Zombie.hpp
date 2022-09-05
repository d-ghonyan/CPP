#pragma once

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	void	announce();
	Zombie();
	Zombie(std::string name);
	~Zombie();
};
