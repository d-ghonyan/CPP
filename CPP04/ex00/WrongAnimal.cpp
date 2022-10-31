#include "WrongAnimal.hpp"

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "* Wrong Animal noises * \n";
}

WrongAnimal::WrongAnimal(): type("")
{
	std::cout << "WrongAnimal's constructor called!\n";
}

WrongAnimal::WrongAnimal(WrongAnimal &other)
{
	(void)other;
	std::cout << "WrongAnimal copy constructor called!\n";
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &other)
{
	(void)other;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal's destructor called!\n";
}
