#include "Brain.hpp"

void Brain::insert(std::string idea)
{
	if (size == 100)
		size = 0;
	ideas[size++] = idea;
}

std::string Brain::getIdea(size_t index)
{
	if (index >= 100)
		return "Segmentation fault";
	return (ideas[index]);
}

Brain::Brain(): size(0)
{
	std::cout << "Brain constructor called!\n";
	for (size_t i = 0; i < 100; i++)
		ideas[i] = "* Random animal thoughts *";
}

Brain &Brain::operator=(const Brain &other)
{
	if (this == &other)
		return *this;
	for (size_t i = 0; i < other.size; i++)
		ideas[i] = other.ideas[i];
	size = other.size;
	return *this;
}

Brain::Brain(const Brain &other): size(other.size)
{
	std::cout << "Brain copy constructor called!\n";
	for (size_t i = 0; i < other.size; i++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!\n";
}
