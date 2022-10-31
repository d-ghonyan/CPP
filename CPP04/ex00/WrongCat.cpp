#include "WrongCat.hpp"

void WrongCat::makeSound()
{
	std::cout << "Wrong Not Woof!\n";
}

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat's constructor called!\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat's destructor called!\n";
}
