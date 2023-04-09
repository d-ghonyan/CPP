#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"

typedef struct timeval t_timeval;

int	argv_check(char **argv);
double	gettime(t_timeval start);

int main(int argc, char **argv)
{
	t_timeval now;

	if (argc < 3 || argv_check(argv)) return (0);

	PmergeMe merge(argv);

	std::cout.precision(17);

	std::cout << "\nBefore: ";
	merge.print_vector(10);

	gettimeofday(&now, NULL);
	double start = gettime(now);
	merge.sortVector();
	double end = gettime(now);

	std::cout << "After: ";
	merge.print_vector(10);

	std::cout << "\nTime taken by std::vector: " << std::fixed << end - start << " ms\n\n\n"; 

	std::cout << "Before: ";
	merge.print_list(10);

	gettimeofday(&now, NULL);
	start = gettime(now);
	merge.sortList();
	end = gettime(now);

	std::cout << "After: ";
	merge.print_list(10);

	std::cout << "\nTime taken by std::list: " << std::fixed << end - start << " ms\n\n";
}

double	gettime(t_timeval start)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return ((static_cast<double>((now.tv_sec - start.tv_sec) * 1000)
		+ (static_cast<double>(now.tv_usec - start.tv_usec) / 1000)));
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
				return 69;
			}
		}
		try { PmergeMe::str2int(argv[i]); }
		catch (const char *e)
		{ std::cerr << "Error: " << e << '\n'; exit (1); }
	}
	return 0;
}
