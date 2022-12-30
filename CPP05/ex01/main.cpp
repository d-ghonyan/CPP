#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form hello;
		Form hello2("kov", 123, 1);

		std::cout << hello << "\n";
		std::cout << hello2 << "\n";
		hello2.beSigned(Bureaucrat("Debil", 1));
		std::cout << hello2 << "\n";
		hello2.beSigned(Bureaucrat("Debil", 124));
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
}