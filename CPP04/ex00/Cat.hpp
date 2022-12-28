#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &other);
	~Cat();
	Cat& operator=(Cat &other);
	void insertIdea(std::string idea);
	std::string getIdea(size_t index);
	void makeSound() const;
};