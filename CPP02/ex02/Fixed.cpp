#include "Fixed.hpp"

Fixed::Fixed(): fixed(0)
{
	std::cout << "Default constructor called!\n";
}

Fixed::Fixed(const int inp)
{
	fixed = inp * (1 << bits);
	std::cout << "Int constructor called!\n";
}

Fixed::Fixed(const float inp)
{
	fixed = static_cast<int>(inp * (1 << bits));
	std::cout << "Float constructor called!\n";
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed&	Fixed::operator++()
{
	fixed++;

	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);

	++(*this);

	return copy;
}

Fixed&	Fixed::operator--()
{
	fixed--;

	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy(*this);

	--(*this);

	return copy;
}

int		Fixed::toInt(void) const { return (static_cast<int>(fixed) / (1 << bits)); }
float	Fixed::toFloat(void) const { return (static_cast<float>(fixed) / static_cast<float>(1 << bits)); }

void	Fixed::setRawBits(int const raw) { fixed = raw; }
int		Fixed::getRawBits(void) const { return fixed; }

bool	Fixed::operator>(const Fixed& other) const		{ return fixed > other.getRawBits(); }
bool	Fixed::operator<(const Fixed& other) const		{ return fixed < other.getRawBits(); }
bool	Fixed::operator>=(const Fixed& other) const		{ return fixed >= other.getRawBits(); }
bool	Fixed::operator<=(const Fixed& other) const		{ return fixed <= other.getRawBits(); }
bool	Fixed::operator==(const Fixed& other) const		{ return fixed == other.getRawBits(); }
bool	Fixed::operator!=(const Fixed& other) const		{ return fixed != other.getRawBits(); }

Fixed	Fixed::operator+(const Fixed& other) const		{ return Fixed(toFloat() + other.toFloat()); }
Fixed	Fixed::operator-(const Fixed& other) const		{ return Fixed(toFloat() - other.toFloat()); }
Fixed	Fixed::operator/(const Fixed& other) const		{ return Fixed(toFloat() / other.toFloat()); }
Fixed	Fixed::operator*(const Fixed& other) const		{ return Fixed(toFloat() * other.toFloat()); }

Fixed&			Fixed::min(Fixed &a, Fixed &b)			{ return a >= b ? b : a; }
Fixed&			Fixed::max(Fixed &a, Fixed &b)			{ return a >= b ? a : b; }
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)	{ return a >= b ? b : a; }
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)	{ return a >= b ? a : b; }

Fixed::~Fixed() { std::cout << "Destructor called!\n"; }
