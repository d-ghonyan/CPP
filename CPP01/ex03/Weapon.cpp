#include "Weapon.hpp"

Weapon::Weapon(std::string _type): type(_type)
{

}

void	Weapon::settype(std::string type)
{
	this->type = type;
}

std::string	Weapon::gettype()
{
	return (this->type);
}