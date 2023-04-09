#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv)
{
	for (size_t i = 1; argv[i]; ++i) { nums.push_back(str2int(argv[i])); }
}

long PmergeMe::str2int (std::string str)
{
	long 		l;
	const char	*s = str.c_str();

	errno = 0;
	l = strtol(s, NULL, 10);
	if ((errno == ERANGE && (l == LONG_MAX || l == LONG_MIN))
		 || l > INT_MAX || l < INT_MIN)
	{
		throw NumberOutOfRangeException();
	}
	if (errno == EINVAL && l == 0)
	{
		throw InvalidNumberException();
	}
	return l;
}

void PmergeMe::sortList()
{
	t_timeval now;
	double start, end;

	nums_l.erase(nums_l.begin(), nums_l.end());
	gettimeofday(&now, NULL);

	start = gettime(now);

	for (size_t i = 0; i < nums.size(); ++i) { nums_l.push_back(nums[i]); }
	
	merge_sort(nums_l);

	end = gettime(now);

	std::cout << "\nTime taken by std::list: " << std::fixed << end - start << " ms\n\n";

	std::cout << "List after sorting: ";
	print_list(DEFAULT_PRECISION);
}

void PmergeMe::sortVector()
{
	t_timeval now;
	double start, end;

	nums_v.erase(nums_v.begin(), nums_v.end());
	gettimeofday(&now, NULL);

	start = gettime(now);

	for (size_t i = 0; i < nums.size(); ++i) { nums_v.push_back(nums[i]); }
	
	merge_sort(nums_v);

	end = gettime(now);

	std::cout << "Time taken by std::vector: " << std::fixed << end - start << " ms\n\n";

	std::cout << "Vector after sorting: ";
	print_vector(DEFAULT_PRECISION);
}

double PmergeMe::gettime(t_timeval start)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return ((static_cast<double>((now.tv_sec - start.tv_sec) * 1000)
		+ (static_cast<double>(now.tv_usec - start.tv_usec) / 1000)));
}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& lhs) { nums = lhs.nums; return *this; }

const char *PmergeMe::InvalidNumberException::what () const throw() { return "Invalid number"; }
const char *PmergeMe::NumberOutOfRangeException::what () const throw() { return "Number out of range"; }

PmergeMe::~PmergeMe() { }