#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	size_t size = 100;
	Animal *arr[100];

	for (size_t i = 0; i < size / 2; i++)
	{
		arr[i] = new Cat();
	}

	for (size_t i = size / 2; i < size; i++)
	{
		arr[i] = new Dog();
	}
	
	for (size_t i = 0; i < size; i++)
	{
		delete arr[i];
	}
}
