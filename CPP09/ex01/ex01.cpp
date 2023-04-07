#include <iostream>
#include <deque>
#include <sstream>
#include <errno.h>
#include "RPN.hpp"

long str2int (std::string str);
int	argv_check(std::string s);
double str2double (std::string str);

int main(int argc, char **argv)
{
	if (argc != 2) { return (0); }

	try
	{
		RPN rpn(argv[1]);

		rpn.calculate();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
}
