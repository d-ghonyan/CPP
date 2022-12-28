#pragma once

#include <iostream>

class Bureaucrat
{
private:
	int		grade;
	const	std::string	name;
	class	GradeTooHighException : public std::exception { char *what (); };
	class	GradeTooLowException : public std::exception { char *what (); };
public:
	Bureaucrat();
	Bureaucrat(std::string, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	const std::string	getName() const;
	int	getGrade() const;
	void increment(void);
	void decrement(void);
	~Bureaucrat();
}; 
