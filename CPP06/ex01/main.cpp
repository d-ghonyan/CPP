#include "Data.hpp"
#include <iostream>

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	Data a;

	a.hello = 42;
	std::cout << &a << "\n";

	std::cout << serialize(&a) << "\n";
	std::cout << deserialize(serialize(&a)) << "\n";
	
	std::cout << &a << "\n";
	std::cout << a.hello << "\n";
}