#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <random>
#include <ctime>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequest"), is_signed(false), target("Default"), grade_sign(72), grade_exec(45)
{
	std::cout << "RobotomyRequestForm constructor called!\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target): Form("RobotomyRequest"), is_signed(false), target(_target), grade_sign(72), grade_exec(45)
{
	std::cout << "RobotomyRequestForm constructor called!\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): Form("RobotomyRequest"), is_signed(false), target(other.getTarget()), grade_sign(72), grade_exec(45)
{
	std::cout << "RobotomyRequestForm copy constructor called!\n";
	*this = other;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > grade_exec)
		throw Form::GradeTooLowException();
	if (!is_signed)
		throw Form::FormNotSignedException();
	actually_execute();
}

void RobotomyRequestForm::actually_execute() const
{
	std::string strs[2] = { target + " has been robotomized\n", "Robotomy failed on " + target + "\n" };

	std::cout << "* DRILLING NOISES *\n";
	sleep(1);
	srand(time(nullptr));
	std::cout << strs[rand() % 2];		
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	target = other.getTarget();
	return *this;
}

int	RobotomyRequestForm::getGradeExec() const
{
	return grade_exec;
}

int	RobotomyRequestForm::getGradeSign() const
{
	return grade_sign;
}

std::string RobotomyRequestForm::getTarget() const
{
	return target;
}

bool RobotomyRequestForm::getSigned() const
{
	return is_signed;
}

void RobotomyRequestForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > grade_sign)
		throw Form::GradeTooLowException();
	is_signed = true;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called!\n";
}
