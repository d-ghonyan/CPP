#include "Form.hpp"
#include <iostream>

class PresidentialPardonForm : public Form
{
private:
	const int grade_sign, grade_exec;
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	std::string getTarget();
	~PresidentialPardonForm();
};

PresidentialPardonForm::PresidentialPardonForm(): target("Default"), grade_sign(25), grade_exec(5)
{
	std::cout << "PresidentialPardonForm constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target): target(_target), grade_sign(25), grade_exec(5)
{
	std::cout << "PresidentialPardonForm constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm other)
{
	std::cout << "PresidentialPardonForm copy constructor called!\n";
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	target = other.getTarget();
	return *this;
}

std::string PresidentialPardonForm::getTarget()
{
	return target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called!\n";
}
