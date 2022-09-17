#include "HumanB.hpp"

HumanB::HumanB(std::string _name): name(_name)
{

}

HumanB::~HumanB()
{

}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << this->weapon->gettype() << std::endl;
}