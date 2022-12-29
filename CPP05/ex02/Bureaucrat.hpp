#pragma once

#include <iostream>

class Bureaucrat
{
private:
	int		grade;
	const	std::string	name;
	class	GradeTooHighException : public std::exception { const char *what () const throw(); };
	class	GradeTooLowException : public std::exception { const char *what () const throw(); };
public:
	Bureaucrat();
	Bureaucrat(std::string, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	const std::string	getName() const;
	int	getGrade() const;
	void increment(void);
	void decrement(void);
	void signForm();
	~Bureaucrat();
}; 

std::ostream& operator<<(std::ostream &os, const Bureaucrat& b);
