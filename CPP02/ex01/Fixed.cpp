#include "Fixed.hpp"

Fixed::Fixed(const int inp) : fixed(0)
{
	std::cout << "Default constructor called!\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called!\n";
	fixed = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called!\n";
	fixed = other.getRawBits();
	return *this;
}

int Fixed::float_to_fixed(float inp)
{
	return static_cast<int>(inp * (1 << bits));
}

float Fixed::fixed_to_float(int inp)
{
    return (static_cast<float>(inp) / (1 << bits));
}

Fixed::~Fixed() { std::cout << "Destructor called!\n"; }

void Fixed::setRawBits(int const raw)
{
	fixed = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called!\n";
	return fixed;
}
