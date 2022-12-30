#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <unistd.h>
#include <ctime>
#include <iostream>

Base * generate(void)
{
	srand(time(nullptr));
	int	val = rand() % 3;
	
	switch (val)
	{
	case 0:
		std::cout << "Generated A class\n";
		return new A();
	case 1:
		std::cout << "Generated B class\n";
		return new B();
	case 2:
		std::cout << "Generated C class\n";
		return new C();
	}
	return nullptr;
}

void identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);
	
	if (a)
		std::cout << "A\n";
	else if (b)
		std::cout << "B\n";
	else if (c)
		std::cout << "C\n";
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p); (void)a;
		std::cout << "A\n";
		return ;
	} catch(const std::bad_cast& e) { (void)e; }
	try
	{
		B& b = dynamic_cast<B&>(p); (void)b;
		std::cout << "B\n";
		return ;
	} catch(const std::bad_cast& e) { (void)e; }
	try
	{
		C& c = dynamic_cast<C&>(p); (void)c;
		std::cout << "C\n";
	} catch(const std::bad_cast& e) { (void)e; }	
}


int main()
{
	Base * base = generate();
	identify(base);
	identify(*base);
	sleep(1);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
}