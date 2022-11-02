#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Woof!\n";
}

Dog::Dog(): brain(new Brain)
{
	type = "Dog";
	std::cout << "Dog's constructor called!\n";
}

Dog::Dog(const Dog &other): Animal()
{
	brain = new Brain(*(other.brain));
	std::cout << "Dog copy constructor called!\n";
}

void Dog::insertIdea(std::string idea)
{
	brain->insert(idea);
}

std::string Dog::getIdea(size_t index)
{
	return (brain->getIdea(index));
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	delete brain;
	brain = new Brain(*(other.brain));
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog's destructor called!\n";
}
