#include "HumanB.hpp"

HumanB::HumanB(std::string _name): name(_name), weapon(nullptr)
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
	if (!weapon)
		std::cout << name << " has no weapon yet!" << std::endl;
	else
		std::cout << name << " attacks with their " << this->weapon->gettype() << std::endl;
}