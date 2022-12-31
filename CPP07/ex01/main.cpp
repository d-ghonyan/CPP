#include "iter.hpp"
#include <iostream>

void kov(char &c)
{
	c = c + 8;
}

void dzuk(std::string& str)
{
	str += " barev";
}

int main( void ){

	int size = 40;
	char *a = new char[size];
	std::string b[size];

	std::cout << "BEFORE-----------------------------------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		a[i] = i + 48;
		b[i] = "hello" + std::to_string(i);
		std::cout << a[i];
	}
	std::cout << "\n";
	for (int i = 0; i < size; i++) std::cout << b[i] << " ";

	std::cout << "\n";

	::iter(a, size, kov);
	::iter(b, size, dzuk);

	std::cout << "AFTER-----------------------------------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i];
	}
	std::cout << "\n";
	for (int i = 0; i < size; i++) std::cout << b[i] << " ";
	std::cout << "\n";

	return 0;
}
