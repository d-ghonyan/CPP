#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardon"), is_signed(false), target("Default"), grade_sign(25), grade_exec(5)
{
	std::cout << "PresidentialPardonForm constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target): Form("PresidentialPardon"), is_signed(false), target(_target), grade_sign(25), grade_exec(5)
{
	std::cout << "PresidentialPardonForm constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): Form("PresidentialPardon"), is_signed(false), target(other.getTarget()), grade_sign(25), grade_exec(5)
{
	std::cout << "PresidentialPardonForm copy constructor called!\n";
	*this = other;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > grade_exec)
		throw Form::GradeTooLowException();
	if (!is_signed)
		throw Form::FormNotSignedException();
	actually_execute();
}

void PresidentialPardonForm::actually_execute() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox!\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	target = other.getTarget();
	return *this;
}

int	PresidentialPardonForm::getGradeExec() const
{
	return grade_exec;
}

int	PresidentialPardonForm::getGradeSign() const
{
	return grade_sign;
}

std::string PresidentialPardonForm::getTarget() const
{
	return target;
}

bool PresidentialPardonForm::getSigned() const
{
	return is_signed;
}

void PresidentialPardonForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > grade_sign)
		throw Form::GradeTooLowException();
	is_signed = true;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called!\n";
}
