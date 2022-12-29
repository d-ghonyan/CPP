#include "Form.hpp"

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

bool Form::getSigned()
{
	return is_signed;
}

std::string Form::getName()
{
	return name;
}

int Form::getGradeSign()
{
	return grade_sign;
}

int Form::getGradeExec()
{
	return grade_exec;
}

Form::~Form()
{
	std::cout << "Form destructor called!\n";
}