#include <iostream>

class Form
{
private:
	bool	signed;
	const	std::string name;
	const	int grade_sign;
	const	int grade_exec;
	class	GradeTooHighException : public std::exception { const char *what () const throw(); };
	class	GradeTooLowException : public std::exception { const char *what () const throw(); };
public:
	Form();
	Form(const std::string name, const int grade_sign, const int grade_exec;);
	Form(const Form& other);
	bool	getSigned();
	int		getName();
	int		getGradeSign();
	int		getGradeExec();
	Form& operator=(const Form& other);
	~Form();
};

Form::Form(): signed(false), name("Default"), grade_sign(75), grade_exec(30) { }

Form::Form(const Form& other)
{
	std::cout << "Form copy constructor "
	*this = other;
}

Form& Form::operator=(const Form& other)
{

}

bool Form::getSigned()
{

}

const std::string Form::getName()
{
	return name;
}

const int Form::getGradeSign()
{
	return grade_sign;
}

const int Form::getGradeExec()
{
	return grade_exec;
}


Form::~Form()
{
}
