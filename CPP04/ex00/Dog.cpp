#include "Dog.hpp"

void Dog::makeSound()
{
	std::cout << "Woof!\n";
}

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog's constructor called!\n";
}

Dog::~Dog()
{
	std::cout << "Dog's destructor called!\n";
}
