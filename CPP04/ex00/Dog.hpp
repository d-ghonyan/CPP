#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	void makeSound();
};