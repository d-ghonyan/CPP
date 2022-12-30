#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern intern;

	Form *sh = intern.makeForm("asdasdasd", "home");

	if (sh)
		std::cout << *sh << "\n";
	delete sh;
	sh = intern.makeForm("ShrubberyCreation", "home");
	if (sh)
		std::cout << *sh << "\n";
	delete sh;
	sh = intern.makeForm("RobotomyRequest", "Karapet");
	if (sh)
		std::cout << *sh << "\n";
	delete sh;
	sh = intern.makeForm("PresidentialPardon", "Dzuk");
	if (sh)
	{
		std::cout << *sh << "\n";
		sh->beSigned(Bureaucrat("Barev", 1));
		sh->execute(Bureaucrat("Barev", 1));
	}
	delete sh;
	sh = intern.makeForm("hello", "home");
	if (sh)
		std::cout << *sh << "\n";
	delete sh;

	/*
	int main()
	{
		Bureaucrat b = Bureaucrat("hello", 145);

		Form *a = new ShrubberyCreationForm();
		
		std::cout << *a << "\n";
		try
		{
			a->beSigned(b);
			std::cout << "Signed!\n";
			a->execute(b);
			std::cout << "Executed!\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught : " << e.what() << '\n';
		}

		delete a;

		Form *rob = new RobotomyRequestForm();

		try
		{
			std::cout << *rob << "\n";

			rob->beSigned(b);
			std::cout << "Robot Signed!\n";
			b.executeForm(*rob);
			std::cout << "Robot Executed!\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught : " << e.what() << '\n';
		}

		Bureaucrat buwuehfiwed("Barev", 12);

		PresidentialPardonForm abc(buwuehfiwed.getName());

		while (buwuehfiwed.getGrade() != abc.getGradeExec()) buwuehfiwed.increment();

		std::cout << buwuehfiwed.getGrade() << "\n";
		std::cout << abc << "\n";
		try
		{
			abc.beSigned(buwuehfiwed);
			std::cout << "Pardon signed!\n";
			abc.execute(buwuehfiwed);
			std::cout << "Pardon executed!\n";
			buwuehfiwed.executeForm(abc);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Pardon Exception caught : " << e.what() << '\n';
		}
	}
	*/
}