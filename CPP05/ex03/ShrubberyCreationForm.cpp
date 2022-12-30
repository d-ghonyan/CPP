#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreation"), is_signed(false), target("Default"), grade_sign(145), grade_exec(137)
{
	std::cout << "ShrubberyCreationForm constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): Form("ShrubberyCreation"), is_signed(false), target(_target), grade_sign(145), grade_exec(137)
{
	std::cout << "ShrubberyCreationForm constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): Form("ShrubberyCreation"), is_signed(false), target(other.getTarget()), grade_sign(145), grade_exec(137)
{
	std::cout << "ShrubberyCreationForm copy constructor called!\n";
	*this = other;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > grade_exec)
		throw Form::GradeTooLowException();
	if (!is_signed)
		throw Form::FormNotSignedException();
	actually_execute();
}

void ShrubberyCreationForm::actually_execute() const
{
	std::ofstream shrub(target + "_shrubbery");

	if (shrub.fail())
	{
		std::cout << "Sorry, can't open the file\n";
		return ;
	}
	shrub << "	   *    *  ()   *   *\n\
	*        * /\\         *\n\
	      *   /i\\\\    *  *\n\
	    *     o/\\\\  *      *\n\
	 *       ///\\i\\    *\n\
	     *   /*/o\\\\  *    *\n\
	   *    /i//\\*\\      *\n\
	        /o/*\\\\i\\   *\n\
	  *    //i//o\\\\\\\\     *\n\
	    * /*////\\\\\\\\i\\*\n\
	 *    //o//i\\\\*\\\\\\   *\n\
	   * /i///*/\\\\\\\\\\o\\   *\n\
	  *    *   ||     *    *\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	target = other.getTarget();
	return *this;
}

int	ShrubberyCreationForm::getGradeExec() const
{
	return grade_exec;
}

int	ShrubberyCreationForm::getGradeSign() const
{
	return grade_sign;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}

bool ShrubberyCreationForm::getSigned() const
{
	return is_signed;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > grade_sign)
		throw Form::GradeTooLowException();
	is_signed = true;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called!\n";
}
