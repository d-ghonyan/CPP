#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	// std::cout << std::min(5,4) << "\n";
	return 0;
}