#pragma once

#include <iostream>

class Bureaucrat;

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
	std::string		getName() const ;
	bool			getSigned() const ;
	int				getGradeSign() const ;
	int				getGradeExec() const ;
	void			beSigned(const Bureaucrat& b);
	virtual void	execute(Bureaucrat const& executor) const = 0;
	Form& operator=(const Form& other);
	virtual			~Form();
};
