#pragma once

#include "Form.hpp"
#include <iostream>

class ShrubberyCreationForm : public Form
{
private:
	bool is_signed;
	std::string target;
	const int grade_sign, grade_exec;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	void execute(Bureaucrat const& executor) const ;
	void actually_execute() const ;
	std::string		getTarget() const;
	bool			getSigned() const ;
	void			beSigned(const Bureaucrat& b);
	int				getGradeExec() const ;
	int				getGradeSign() const ;
	~ShrubberyCreationForm();
};
