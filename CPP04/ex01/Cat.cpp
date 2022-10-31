#include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "Not Woof!\n";
}

Cat::Cat(): brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat's constructor called!\n";
}

Cat::Cat(const Cat &other): Animal()
{
	*brain = *(other.brain);
	std::cout << "Cat copy constructor called!\n";
}

void Cat::insertIdea(std::string idea)
{
	brain->insert(idea);
}

std::string Cat::getIdea(size_t index)
{
	return (brain->getIdea(index));
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	delete brain;
	brain = new Brain(*(other.brain));
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called!\n";
}
