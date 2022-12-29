#pragma once

#include "Form.hpp"
#include <iostream>

class ShrubberyCreationForm : public Form
{
private:
	std::string target;
	const int grade_sign, grade_exec;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	void execute(Bureaucrat const& executor) const ;
	std::string getTarget() const;
	~ShrubberyCreationForm();
};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
}

ShrubberyCreationForm::ShrubberyCreationForm(): target("Default"), grade_sign(145), grade_exec(137)
{
	std::cout << "ShrubberyCreationForm constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): target(_target), grade_sign(145), grade_exec(137)
{
	std::cout << "ShrubberyCreationForm constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): Form(), target(other.getTarget()), grade_sign(145), grade_exec(137)
{
	std::cout << "ShrubberyCreationForm copy constructor called!\n";
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	target = other.getTarget();
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called!\n";
}
