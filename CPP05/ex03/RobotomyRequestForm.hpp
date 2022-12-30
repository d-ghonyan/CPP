#pragma once

#include "Form.hpp"
#include <iostream>

class RobotomyRequestForm : public Form
{
private:
	bool is_signed;
	std::string target;
	const int grade_sign, grade_exec;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	void execute(Bureaucrat const & executor) const ;
	void actually_execute() const ;
	std::string		getTarget() const;
	bool			getSigned() const ;
	void			beSigned(const Bureaucrat& b);
	int				getGradeExec() const ;
	int				getGradeSign() const ;
	~RobotomyRequestForm();
};
