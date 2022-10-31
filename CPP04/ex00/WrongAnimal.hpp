#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal &other);
	~WrongAnimal();
	WrongAnimal &operator=(WrongAnimal &other);
	void makeSound() const;
	std::string getType() const;
};