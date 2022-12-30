#include "Intern.hpp"

typedef Form *(Intern::*hello)(std::string target);

Form *Intern::makeShrub(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeRobot(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form *Intern::makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(std::string name, std::string target)
{
	std::string arr[3] = { "ShrubberyCreation", "RobotomyRequest", "PresidentialPardon" };

	hello func_arr[3] = { &Intern::makeShrub, &Intern::makeRobot, &Intern::makePardon };

	size_t i;
	
	for (i = 0; name != arr[i] && i < 10; i++);

	if (i != 10) return (this->*(func_arr[i]))(target);

	std::cout << "Can't find a form with that name!\n";
	return nullptr;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called!\n";
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::Intern()
{
	std::cout << "Intern constructor called!\n";
}

Intern::~Intern()
{
	std::cout << "Intern destructor called!\n";
}
