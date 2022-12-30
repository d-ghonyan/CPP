#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
protected:
	class	GradeTooHighException : public std::exception { const char *what () const throw(); };
	class	GradeTooLowException : public std::exception { const char *what () const throw(); };
	class	FormNotSignedException : public std::exception { const char *what () const throw(); };
private:
	bool	is_signed;
	const	std::string name;
	const	int grade_sign;
	const	int grade_exec;
public:
	Form();
	Form(const std::string _name);
	Form(const std::string _name, const int _grade_sign, const int _grade_exec);
	Form(const Form& other);
	std::string				getName() const ;
	virtual bool			getSigned() const ;
	virtual int				getGradeSign() const ;
	virtual int				getGradeExec() const ;
	virtual void			beSigned(const Bureaucrat& b);
	virtual void			execute(Bureaucrat const& executor) const = 0;
	Form& operator=(const Form& other);
	virtual			~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& f);
