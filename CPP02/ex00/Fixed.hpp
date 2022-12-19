#pragma once
#include <iostream>

class Fixed
{
private:
	static const int bits = 0;
public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();
	Fixed	operator=(const Fixed& other);
	int		getRawBits(void) const;
	int		setRawBits(int const raw);
};

Fixed::Fixed() { std::cout << "Default constructor called!\n"; }

Fixed::Fixed(const Fixed& other) { (void)other; std::cout << "Copy constructor called!\n"; }

Fixed::~Fixed() { std::cout << "Destructor called!\n"; }

int	Fixed::getRawBits(void) const
{
	return static_cast<int>(std::bitset<8>(0).to_ulong());
}