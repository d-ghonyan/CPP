#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	~Dog();
	Dog &Dog::operator=(Dog &other);
	void makeSound() const;
};