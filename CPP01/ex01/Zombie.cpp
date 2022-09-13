#include "Zombie.hpp"

Zombie::Zombie()
{
	
}

Zombie::Zombie(std::string _name) : name ( _name )
{

}

void	Zombie::setname(std::string name)
{
	this->name = name;
	if (name.empty())
		this->name = "empty";
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << ": i'm dyyyyiiiiiing" << std::endl;
}
