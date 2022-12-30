#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): grade(150), name("Default")
{
	std::cout << "Bureaucrat Constructor called\n";
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): grade(_grade), name(_name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat constructor called\n";
}

void Bureaucrat::executeForm(Form const& form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " couldn't execute " << form.getName() << " because " << e.what() << '\n';
	}
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't sign " << form.getName() <<  " because " << e.what() << "\n";
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Bureaucrat Copy Constructor called\n";
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	grade = other.grade;
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void Bureaucrat::increment(void)
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement(void)
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

const std::string	Bureaucrat::getName() const
{
	return name;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called\n";
}
