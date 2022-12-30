#pragma once

#include "Form.hpp"
#include <iostream>

class PresidentialPardonForm : public Form
{
private:
	bool is_signed;
	std::string target;
	const int grade_sign, grade_exec;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	void execute(Bureaucrat const & executor) const ;
	void actually_execute() const ;
	std::string		getTarget() const;
	bool			getSigned() const ;
	void			beSigned(const Bureaucrat& b);
	int				getGradeExec() const ;
	int				getGradeSign() const ;
	~PresidentialPardonForm();
};
