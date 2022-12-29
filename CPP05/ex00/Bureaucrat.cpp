#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): grade(150), name("Default")
{
	std::cout << "Constructor called\n";
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): grade(_grade), name(_name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Constructor called\n";
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Copy Constructor called\n";
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	grade = other.grade;
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return "Grade too low";
}

void Bureaucrat::increment(void)
{
	if (grade == 1)
		throw Bureaucrat::GradeTooLowException();
	grade--;
}

void Bureaucrat::decrement(void)
{
	if (grade == 150)
		throw Bureaucrat::GradeTooHighException();
	grade++;
}


const std::string	Bureaucrat::getName() const
{
	return name;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called\n";
}
