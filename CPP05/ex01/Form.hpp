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
	Form(const Form& other);
	bool	getSigned();
	int		getName();
	int		getGradeSign();
	int		getGradeExec();
	Form& operator=(const Form& other);
	~Form();
};

Form::Form()
{
}

Form::Form(const Form& other)
{

}

Form& Form::operator=(const Form& other)
{

}

bool	Form::getSigned()
{

}

int		Form::getName()
{

}

int		Form::getGradeSign()
{

}

int		Form::getGradeExec()
{

}


Form::~Form()
{
}
