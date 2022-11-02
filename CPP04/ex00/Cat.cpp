#include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "Not Woof!\n";
}

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat's constructor called!\n";
}

Cat &Cat::operator=(Cat &other)
{
	(void)other;
	return (*this);
}

Cat::Cat(const Cat &other)
{
	(void)other;
	std::cout << "Cat copy constructor called!\n";
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called!\n";
}
