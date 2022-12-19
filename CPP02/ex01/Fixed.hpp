#pragma once
#include <iostream>

class Fixed
{
private:
	int					fixed;
	static const int	bits = 0;
public:
	Fixed(const int inp);
	Fixed(const Fixed &other);
	~Fixed();
	Fixed&	operator=(const Fixed& other);
	int		float_to_fixed(float inp);
	float	fixed_to_float(int inp);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
