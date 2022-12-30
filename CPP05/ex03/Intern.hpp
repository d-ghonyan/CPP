#pragma once

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
private:
	Form *makeShrub(std::string target);
	Form *makeRobot(std::string target);
	Form *makePardon(std::string target);
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	Form *makeForm(std::string name, std::string target);
	~Intern();
};
