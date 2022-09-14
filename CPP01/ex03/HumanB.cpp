#include "HumanB.hpp"

HumanB::HumanB(std::string _name): name(_name)
{

}

HumanB::~HumanB()
{
	delete this->weapon;
}

void	HumanB::setWeapon(Weapon weapon)
{
	delete this->weapon;
	this->weapon = new Weapon(weapon.gettype());
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << this->weapon->gettype() << std::endl;
}