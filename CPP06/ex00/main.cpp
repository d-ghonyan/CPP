#include <iostream>
#include <string>

std::string special(std::string hello);

std::string ft_tolower(std::string hello, bool is_double);

bool is_int(std::string hello);

void print_float(std::string hello, double num);

bool is_float(std::string _hello, bool is_double);

void convert(std::string hello)
{
	if (is_int(hello))
	{
			
		try
		{
			int num;
			
			if (hello.size() == 1 && (hello[0] < '0' || hello[0] > '9'))
				num = static_cast<char>(hello[0]);
			else
				num = std::stoi(hello);

			std::cout << "char: ";

			if (num < -128 || num > 127)
				std::cout << "impossible\n";
			else if (num >= 32 && num < 127)
				std::cout << static_cast<char>(num) << "\n";
			else
				std::cout << "non-displayable\n";
			std::cout << "int: " << num << "\n";
			std::cout << "float: " << static_cast<float>(num) << ".0f\n";
			std::cout << "double: " << static_cast<double>(num) << ".0\n";
		}
		catch (const std::exception& e)
		{
			std::cout << "Can't convert to int: " << e.what() << "\n";
		}
	}
	else if (is_float(hello, false))
	{
		try
		{
			float num = std::stof(hello);

			print_float(hello, static_cast<double>(num));
			std::cout << "float: " << num << "f\n";
			std::cout << "double: " << static_cast<double>(num) << "\n";
		}
		catch (const std::exception& e)
		{
			std::cout << "Can't convert to int: " << e.what() << "\n";
		}
	}
	else if (is_float(hello, true))
	{
		try
		{
			double num = std::stod(hello);

			print_float(hello, num);
			std::cout << "float: " << static_cast<float>(num) << "f\n";
			std::cout << "double: " << num << "\n";
		}
		catch (const std::exception& e)
		{
			std::cout << "Can't convert to int: " << e.what() << "\n";
		}
	}
	else
		std::cout << "Invalid value.\n";
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::string hello(argv[1]);

	convert(hello);
}