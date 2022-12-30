#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

Form& Form::operator=(const Form& other)
{
	(void)other;
	return *this;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > grade_sign)
		throw Form::GradeTooLowException();
	is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", form sign grade " << f.getGradeSign() << ", form exec grade " << f.getGradeExec() << ", is signed - " << (f.getSigned() ? "true" : "false");
	return os;
}

Form::Form(): is_signed(false), name("Default"), grade_sign(75), grade_exec(30) { std::cout << "Form default constructor called!\n"; }

Form::Form(const Form& other): is_signed(false), name("Default"), grade_sign(75), grade_exec(30)
{
	std::cout << "Form copy constructor\n";
	*this = other;
}

Form::Form(const std::string _name, const int _grade_sign, const int _grade_exec):
	is_signed(false), name(_name), grade_sign(_grade_sign), grade_exec(_grade_exec)
{
	if (_grade_sign > 150 || _grade_exec > 150)
		throw Form::GradeTooLowException();
	if (_grade_sign < 1 || _grade_exec < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form default constructor\n";
}

bool Form::getSigned() const
{
	return is_signed;
}

std::string Form::getName() const
{
	return name;
}

int Form::getGradeSign() const
{
	return grade_sign;
}

int Form::getGradeExec() const
{
	return grade_exec;
}

Form::~Form()
{
	std::cout << "Form destructor called!\n";
}