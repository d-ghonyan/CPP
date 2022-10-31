#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog *dog = new Dog();
	//Animal *cat = new Cat();

	Dog a(*dog);

	delete dog;

	while (1);
}
