#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	bool	is_signed;
	const	std::string name;
	const	int grade_sign;
	const	int grade_exec;
	class	GradeTooHighException : public std::exception { const char *what () const throw(); };
	class	GradeTooLowException : public std::exception { const char *what () const throw(); };
public:
	Form();
	Form(const std::string _name, const int _grade_sign, const int _grade_exec);
	Form(const Form& other);
	std::string		getName();
	bool			getSigned();
	int				getGradeSign();
	int				getGradeExec();
	void			beSigned(const Bureaucrat& b);
	Form& operator=(const Form& other);
	~Form();
};

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > grade_sign)
		throw Form::GradeTooLowException();
	is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", form sign grade " << f.getGradeSign() << ", form exec grade " << f.getGradeExec() << ", is signed - " << f.getSigned();
	return os;
}

Form::Form(): is_signed(false), name("Default"), grade_sign(75), grade_exec(30) { }

Form::Form(const Form& other): is_signed(false), name("Default"), grade_sign(75), grade_exec(30)
{
	std::cout << "Form copy constructor\n";
	*this = other;
}

Form::Form(const std::string _name, const int _grade_sign, const int _grade_exec): is_signed(false)
{
	if (_grade_sign > 150 || _grade_exec > 150)`
		throw Form::GradeTooLowException();
	if (_grade_sign < 1 || _grade_exec < 1)
		throw Form::GradeTooHighException();
	name = _name;
	grade_exec = _grade_exec;
	grade_sign = _grade_sign;
}

