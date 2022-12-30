#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Form *a = new ShrubberyCreationForm();

	// a->beSigned(b);
	// a->execute(b);
	// std::cout << a->getGradeExec() << "\n";
	// delete a;



	// Bureaucrat b = Bureaucrat("hello", 145);

	// Form *shrub = new ShrubberyCreationForm();

	// std::cout << *shrub << "\n";

	// shrub->beSigned(b);

	// b.executeForm(*shrub);

	Intern intern;

	Form *sh = intern.makeForm("asdasdasd", "home");

	if (sh)
		std::cout << *sh;
	// RobotomyRequestForm ab;
	// std::cout << "Sign: " << ab.getGradeSign() << ", Exec: " << ab.getGradeExec() << "\n";

	// try
	// {
	// 	ab.beSigned(b);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Exception: " << e.what() << '\n';
	// }
	
	// try
	// {
	// 	ab.execute(b);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Execution: " << e.what() << '\n';
	// }
	
	// PresidentialPardonForm abc;

	// abc.beSigned(b);
	// abc.execute(b);
	// try
	// {
	// 	Bureaucrat a("asjkdhasd", 150);
	// 	std::cout << a << "\n";
	// 	std::cout << a.getGrade() << "\n";
	// 	std::cout << a.getName() << "\n";
	// 	a.increment();
	// 	std::cout << a.getGrade() << "\n";
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}