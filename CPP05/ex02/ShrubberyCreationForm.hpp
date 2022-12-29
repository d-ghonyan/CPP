#include "Form.hpp"
#include <iostream>

class ShrubberyCreationForm : public Form
{
private:
	const int grade_sign, grade_exec;
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	std::string getTarget();
	~ShrubberyCreationForm();
};

ShrubberyCreationForm::ShrubberyCreationForm(): target("Default"), grade_sign(145), grade_exec(137)
{
	std::cout << "ShrubberyCreationForm constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): target(_target), grade_sign(145), grade_exec(137)
{
	std::cout << "ShrubberyCreationForm constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm other)
{
	std::cout << "ShrubberyCreationForm copy constructor called!\n";
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	target = other.getTarget();
	return *this;
}

std::string ShrubberyCreationForm::getTarget()
{
	return target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called!\n";
}
