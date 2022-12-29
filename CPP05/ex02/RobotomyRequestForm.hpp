#include "Form.hpp"
#include <iostream>

class RobotomyRequestForm : public Form
{
private:
	const int grade_sign, grade_exec;
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	std::string getTarget();
	~RobotomyRequestForm();
};

RobotomyRequestForm::RobotomyRequestForm(): target("Default"), grade_sign(72), grade_exec(45)
{
	std::cout << "RobotomyRequestForm constructor called!\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target): target(_target), grade_sign(72), grade_exec(45)
{
	std::cout << "RobotomyRequestForm constructor called!\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm other)
{
	std::cout << "RobotomyRequestForm copy constructor called!\n";
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	target = other.getTarget();
	return *this;
}

std::string RobotomyRequestForm::getTarget()
{
	return target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called!\n";
}
