#include "Fixed.hpp"

Fixed::Fixed(): fixed(0)//, min(std::numeric_limits<float>::min())
{
	std::cout << "Default constructor called!\n";
}

Fixed::Fixed(const int inp)//: min(std::numeric_limits<float>::min())
{
	fixed = inp * (1 << bits);
	std::cout << "Int constructor called!\n";
}

Fixed::Fixed(const float inp)//: min(std::numeric_limits<float>::min())
{
	fixed = static_cast<int>(inp * (1 << bits));
	std::cout << "Float constructor called!\n";
}

Fixed&	Fixed::operator++()
{
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);

	++(*this);

	return copy;
}

// float Fixed::fixed_to_float(int inp)
// {
// 	return (static_cast<float>(inp) / (1 << bits));
// }

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

int Fixed::toInt(void) const
{
	// return static_cast<int>(fixed * (1 << bits));
	return (static_cast<int>(fixed) / (1 << bits));
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed) / static_cast<float>(1 << bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
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
