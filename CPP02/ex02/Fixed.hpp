#pragma once
#include <iostream>
#include <limits>

class Fixed
{
private:
	int					fixed;
	static const int	bits = 8;
	const float	min = std::numeric_limits<float>::min();
public:
	Fixed();
	Fixed(const int inp);
	Fixed(const float inp);
	Fixed(const Fixed &other);
	~Fixed();
	Fixed&	operator=(const Fixed& other);
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator>(const Fixed& other);
	Fixed&	operator>=(const Fixed& other);
	Fixed&	operator<(const Fixed& other);
	Fixed&	operator<=(const Fixed& other);
	Fixed&	operator==(const Fixed& other);
	Fixed&	operator!=(const Fixed& other);
	Fixed&	operator+(const Fixed& other);
	Fixed&	operator-(const Fixed& other);
	Fixed&	operator/(const Fixed& other);
	Fixed&	operator*(const Fixed& other);
	int		toInt( void ) const;
	float	toFloat( void ) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);