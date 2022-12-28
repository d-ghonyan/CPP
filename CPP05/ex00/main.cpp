#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("asjkdhasd", 151);

	std::cout << a.getGrade() << "\n";
	std::cout << a.getName() << "\n";
	a.increment();
	std::cout << a.getGrade() << "\n";
}