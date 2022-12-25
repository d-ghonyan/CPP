#pragma once
#include <iostream>
#include <limits>

class Fixed
{
private:
	int				fixed;
	static const	int	bits = 8;
public:
	Fixed();
	Fixed(const int inp);
	Fixed(const float inp);
	Fixed(const Fixed &other);
	~Fixed();
	Fixed&	operator=(const Fixed& other);
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	bool	operator>(const Fixed& other) const ;
	bool	operator>=(const Fixed& other) const ;
	bool	operator<(const Fixed& other) const ;
	bool	operator<=(const Fixed& other) const ;
	bool	operator==(const Fixed& other) const ;
	bool	operator!=(const Fixed& other) const ;
	Fixed	operator+(const Fixed& other) const ;
	Fixed	operator-(const Fixed& other) const ;
	Fixed	operator/(const Fixed& other) const ;
	Fixed	operator*(const Fixed& other) const ;
	int		toInt( void ) const;
	float	toFloat( void ) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	static Fixed&	max(Fixed &a, Fixed &b);
	static const 	Fixed&	max(const Fixed &a, const Fixed &b);
	static Fixed&	min(Fixed &a, Fixed &b);
	static const 	Fixed&	min(const Fixed &a, const Fixed &b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);