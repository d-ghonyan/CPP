#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("asjkdhasd", 150);
		std::cout << a << "\n";
		std::cout << a.getGrade() << "\n";
		std::cout << a.getName() << "\n";
		a.increment();
		std::cout << a.getGrade() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}