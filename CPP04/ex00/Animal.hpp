#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(Animal &other);
	~Animal();
	Animal &operator=(Animal &other);
	virtual void makeSound();
};