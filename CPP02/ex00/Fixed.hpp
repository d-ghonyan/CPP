#pragma once
#include <iostream>

class Fixed
{
private:
	int					fixed;
	static const int	bits = 8;
public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();
	Fixed&	operator=(const Fixed& other);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
