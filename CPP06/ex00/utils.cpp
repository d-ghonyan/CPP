#include <iostream>
#include <string>

std::string special(std::string hello)
{
	if (hello == "nanf" || hello == "+inff" || hello == "-inff"
		|| hello == "nan" || hello == "+inf" || hello == "-inf" || hello == "inf" || hello == "inff")
		return hello;
	return "";
}

std::string ft_tolower(std::string hello, bool is_double)
{
	std::string hellonew(hello);

	for (size_t i = 0; i < hello.size(); ++i) hellonew[i] = std::tolower(hello[i]);

	if (!is_double && special(hello) == "" && hellonew[hellonew.size() - 1] == 'f')
		hellonew = hellonew.substr(0, hellonew.size() - 1);
	return hellonew;
}

bool is_int(std::string hello)
{
	size_t i = 0;

	if (hello.size() == 1)
		return true;

	while (std::isspace(hello[i])) ++i ;

	if (hello[i] == '+' || hello[i] == '-') ++i;

	for (; i < hello.size(); ++i)
	{
		if (hello[i] < '0' || hello[i] > '9')
			return false;
	}

	return true;
}

void print_float(std::string hello, double num)
{
	if (special(hello) != "")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else
	{
		char c = static_cast<char>(num);
		int i = static_cast<int>(num);

		std::cout << "char: ";

		if (i < -128 || i > 127)
			std::cout << "impossible\n";
		else if (i >= 32 && i < 127)
			std::cout << c << "\n";
		else
			std::cout << "non-displayable\n";
		
		std::cout << "int: " << i << "\n";
	}
}

bool is_float(std::string _hello, bool is_double)
{
	size_t i = 0;
	bool point = false;
	std::string hello;

	hello = ft_tolower(_hello, is_double);

	if (
		(!is_double && (hello == "nanf" || hello == "+inff" || hello == "-inff" || hello == "inff"))
		|| (is_double && (hello == "nan" || hello == "+inf" || hello == "-inf" || hello == "inf"))
		)
		return true;

	while (std::isspace(hello[i])) ++i ;

	if (hello[i] == '+' || hello[i] == '-') ++i;

	for (; i < hello.size(); ++i)
	{
		if (hello[i] == '.' && !point)
			point = true;
		else if (hello[i] == '.' && point)
			return false;
		if ((hello[i] < '0' || hello[i] > '9') && hello[i] != '.')
			return false;
	}
	return true;
}
