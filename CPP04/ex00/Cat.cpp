#include "Cat.hpp"

void Cat::makeSound()
{
	std::cout << "Woof!\n";
}

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat's constructor called!\n";
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called!\n";
}
