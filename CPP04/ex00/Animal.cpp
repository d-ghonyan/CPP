#include "Animal.hpp"

void Animal::makeSound()
{
	std::cout << "* Animal noises * \n";
}

Animal::Animal(): type("")
{
	std::cout << "Animal's constructor called!\n";
}

Animal::Animal(Animal &other)
{
	(void)other;
	std::cout << "Animal copy constructor called!\n";
}

Animal &Animal::operator=(Animal &other)
{
	(void)other;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal's destructor called!\n";
}
