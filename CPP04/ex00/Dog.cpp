#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Woof!\n";
}

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog's constructor called!\n";
}

Dog &Dog::operator=(Dog &other)
{
	(void)other;
	return (*this);
}

Dog::Dog(const Dog &other)
{
	(void)other;
	std::cout << "Dog copy constructor called!\n";
}

Dog::~Dog()
{
	std::cout << "Dog's destructor called!\n";
}
