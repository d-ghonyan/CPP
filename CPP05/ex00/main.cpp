#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("asjkdhasd", 150);
		std::cout << a << "\n";
		std::cout << a.getGrade() << "  1  \n";
		std::cout << a.getName() << "   2  \n";
		a.increment();
		std::cout << a.getGrade() << "  3  \n";
		a.decrement();
		std::cout << a.getGrade() << "  4  \n";
		a.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception thrown : " << e.what() << '\n';
	}
}