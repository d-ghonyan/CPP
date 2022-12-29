#pragma once

#include "Form.hpp"
#include <iostream>

class PresidentialPardonForm : public Form
{
private:
	std::string target;
	const int grade_sign, grade_exec;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	void execute(Bureaucrat const & executor) const ;
	std::string getTarget() const ;
	~PresidentialPardonForm();
};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
}

PresidentialPardonForm::PresidentialPardonForm(): target("Default"), grade_sign(25), grade_exec(5)
{
	std::cout << "PresidentialPardonForm constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target): target(_target), grade_sign(25), grade_exec(5)
{
	std::cout << "PresidentialPardonForm constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): Form(), target(other.getTarget()), grade_sign(25), grade_exec(5)
{
	std::cout << "PresidentialPardonForm copy constructor called!\n";
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	target = other.getTarget();
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called!\n";
}
