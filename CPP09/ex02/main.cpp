#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"

int	argv_check(char **argv);

int main(int argc, char **argv)
{
	if (argc < 3 || argv_check(argv)) return (0);

	std::cout.precision(17);
	try
	{
		std::cout << "\n";

		PmergeMe merge(argv);

		merge.sortVector();
		merge.sortList();

		std::cout << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
}

int	argv_check(char **argv)
{
	for (size_t i = 1; argv[i]; ++i)
	{
		for (size_t j = 0; argv[i][j]; ++j)
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				std::cerr << "Error: I accept only digits\n";
				return 1;
			}
		}
		try { PmergeMe::str2int(argv[i]); }
		catch (const char *e)
		{ std::cerr << "Error: " << e << '\n'; exit (1); }
	}
	return 0;
}
